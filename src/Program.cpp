/**
 * Project Lutin
 */

#include <iostream>
#include <algorithm>
#include <cstring>

#include "Program.h"
#include "Assignment.h"
#include "Operation.h"
#include "Operator.h"
#include "Read.h"
#include "Write.h"
#include "Value.h"
#include "NestedExpression.h"
#include "Utils.h"
#include "Operator.h"

bool operator<(const std::string &s1, const std::string &s2)
{
	return strcmp(s1.c_str(), s2.c_str()) < 0;
}

/**
 * Program implementation
 */

Program::Program()
{
}

Program::~Program()
{
	std::vector<Instruction*>::iterator itInst;
	std::map<std::string, Variable*>::iterator itVar;
	
	for(itInst = instructions.begin(); itInst != instructions.end(); ++itInst)
	{
		delete *itInst;
	}

	for(itVar = variables.begin(); itVar != variables.end(); ++itVar)
	{
		delete itVar->second;
	}
}

void Program::Build(const Word *word)
{
	WordContainer *container = word->GetVal().wordContainer;
	switch(word->GetSymbol())
	{
		case SYM_P: // Program
			break;

		case SYM_Pd:
			if(container->size) // Pd -> Pd D pv
			{
				Build(container->words[0]);
				Build(container->words[1]);
			}
			return;

		case SYM_D:
			Build(container->words[1]);
			return;

		case SYM_Lval:
			if(container->size == 1) // Lval -> id
			{
				std::string *id = container->words[0]->GetVal().varid;

				addVariable(new Variable(*id));
			}
			else if(container->size == 3) // Lval -> Lval vg id
			{
				std::string *id = container->words[2]->GetVal().varid;
				
				addVariable(new Variable(*id));
				Build(container->words[0]);
			}
			return;

		case SYM_Lconst:
			if(container->words[0]->GetSymbol() == SYM_Lconst) // Lconst -> Lconst vg Lconst
			{
				Build(container->words[0]);
				Build(container->words[2]);
			}
			else // Lconst -> id = n
			{
				std::string *name = container->words[0]->GetVal().varid;
				int *value = container->words[2]->GetVal().number;

				addVariable(new Constant(*name, *value));
			}
			return;

		case SYM_Pi:
			if(container->size) // Pi -> Pi I pv
			{
				Build(container->words[0]);
				Build(container->words[1]);
			}
			return;

		case SYM_I:
			if(container->size == 3) // I -> id aff E
			{
				std::string *id = container->words[0]->GetVal().varid;
				Variable *var = getGrammarVariable(*id);
				Expression *e = buildExpression(container->words[2]);
				instructions.push_back(new Assignment(var, e));
			}
			else
			{
				Symbol firstSymbol = container->words[0]->GetSymbol();
				if(firstSymbol == SYM_w) // I -> w E
				{
					Expression *e = buildExpression(container->words[1]);
					instructions.push_back(new Write(e));
				}
				else if(firstSymbol == SYM_r) // I -> r id
				{
					std::string *id = container->words[1]->GetVal().varid;
					Variable *var = getGrammarVariable(*id);
					instructions.push_back(new Read(var));
				}
			}
			return;
		default:
			std::cout << "WTF ("<< (int)word->GetSymbol() << ")" << std::endl;
			return;
	}

	for(unsigned int i = 0; i < word->GetVal().wordContainer->size; ++i)
		Build(word->GetVal().wordContainer->words[i]); 
}

void Program::DisplayCode(void) 
{
	for(std::map<std::string, Variable*>::iterator itV = variables.begin(); itV != variables.end(); ++itV)
		std::cout << itV->second->GetDeclaration() << std::endl;
	for (std::vector<Instruction*>::iterator itI = instructions.begin() ; itI != instructions.end(); ++itI)
		(*itI)->Display();
}

void Program::StaticAnalysis(void)
{
	std::set<const Variable*> declaredVar;
	std::set<const Variable*> affectedVar;
	std::map<std::string, Variable*>::iterator itVar;
	std::set<const Variable*> varInstr;
	std::vector<Instruction*>::iterator it;
	std::vector<Instruction*>::iterator itBis;
	std::set<const Variable*> diff;
	std::set<const Variable*>::const_iterator itDiff;
	std::set<const Variable*> rightPart;

	for(it = instructions.begin(); it != instructions.end(); ++it) 
	{
		(*it)->GetVariables(varInstr);
		(*it)->GetVariables(rightPart, true);
	}

	for(itVar = variables.begin(); itVar != variables.end(); ++itVar)
	{
		Variable* var = itVar->second;
		if(!var->GetGhost())
		{
			declaredVar.insert(var);
		}
	}

	//Var used but not declared
	//Inserts in set "diff" : varInstr - declaredVar 
	std::set_difference(varInstr.begin(), varInstr.end(), declaredVar.begin(), declaredVar.end(), 
                        std::inserter(diff, diff.begin()));
	if(!diff.empty())
	{
		for(itDiff = diff.begin(); itDiff != diff.end(); ++itDiff) 
		{
			std::cerr << "ERROR: Variable "+ (*itDiff)->GetName() +" used but not declared." << std::endl;
		}
	}

	diff.clear();

	//Var declared but not used
	//Inserts in set "diff" : declaredVar - rightPart
	std::set_difference(declaredVar.begin(), declaredVar.end(), rightPart.begin(), rightPart.end(), 
                        std::inserter(diff, diff.begin()));
	if(!diff.empty())
	{
		for(itDiff = diff.begin(); itDiff != diff.end(); ++itDiff)
		{
			std::cerr << "WARNING: Variable "+ (*itDiff)->GetName() +" not used." << std::endl;
		}
	}

	//Var used but not affected
	varInstr.clear();
	for(it = instructions.begin(); it != instructions.end(); ++it) 
	{
		//Get the variables of the current instruction
		(*it)->GetVariables(varInstr, true);

		for(itDiff = varInstr.begin(); itDiff != varInstr.end(); ++itDiff)
		{
			const Variable* var = (*itDiff);
			if(var != 0 && !var->IsConstant() && affectedVar.find(var) == affectedVar.end())
			{
				std::cerr << "ERROR: Variable " + (*itDiff)->GetName() + " isn't initialized." << std::endl;
			}
		}
		affectedVar.insert((*it)->GetAssignedVar());
		varInstr.clear();
	}
	
	//Checks if assigned or read variables aren't constant
	Variable* var;

	for(it = instructions.begin(); it != instructions.end(); ++it) 
	{
		var = (*it)->GetAssignedVar();

		if(var != 0 && var->IsConstant())
		{
			std::cerr << "ERROR: Constant " + (var->GetName()) + " cannot be modified." << std::endl;
		}
	}
}

bool Program::addVariable(Variable *variable)
{
	bool newVar = variables.insert(std::pair<std::string, Variable*>(variable->GetName(), variable)).second;

	if(!newVar) // A variable or constant already exists with the given name
	{
		std::cerr << "la variable " << variable->GetName() << " est deja declaree" << std::endl;
		
		// Delete the new variable, since std::map::insert does not insert if the key already exists
		delete variable;
	}

	return newVar;
}

Variable *Program::getGrammarVariable(const std::string &id)
{
	Variable *v;
	std::map<std::string, Variable*>::iterator it = variables.find(id);
	if(it != variables.end())
		return it->second;
	
	v = new Variable(id, true);
	addVariable(v);
	return v;
}

Expression *Program::buildExpression(const Word *w)
{
	WordContainer *container = w->GetVal().wordContainer;

	if(container->size == 1)
	{
		Symbol symbol = container->words[0]->GetSymbol();
		if(symbol == SYM_id) // E -> id
		{
			std::string *id = container->words[0]->GetVal().varid;
			return getGrammarVariable(*id);
		}
		else if(symbol == SYM_n) // E -> n
		{
			Value *value = new Value();
			value->Set(*(container->words[0]->GetVal().number));
			return value;
		}
	}
	else // Size should be 3
	{
		Symbol symbol = container->words[1]->GetSymbol();
		if(symbol == SYM_E) // E -> ( E )
		{
			Expression *e = buildExpression(container->words[1]);
			return new NestedExpression(e);
		}
		else // E -> E op E
		{
			Expression *e1 = buildExpression(container->words[0]);
			Expression *e2 = buildExpression(container->words[2]);
			
			if(symbol == SYM_plus) // E -> E + E
			{
				return new Operation(e1, OP_PLUS, e2);
			}
			else if(symbol == SYM_times) // E -> E * E
			{
				return new Operation(e1, OP_TIMES, e2);
			}
			else if(symbol == SYM_minus) // E -> E - E
			{
				return new Operation(e1, OP_MINUS, e2);
			}
			else if(symbol == SYM_div) // E -> E / E
			{
				return new Operation(e1, OP_DIVIDE, e2);
			}
		}
	}

	return 0;
}

void Program::Optimize(void) 
{
	std::map<std::string, Variable*>::iterator itVar;
	std::map<Variable*, int> varKnown;
	for(std::vector<Instruction*>::iterator it = instructions.begin(); it != instructions.end(); ++it)
	{
		(*it)->Optimize(varKnown);
	}
}

void Program::Execute(void) 
{
	for(std::vector<Instruction*>::iterator itI = instructions.begin(); itI != instructions.end(); ++itI)
	{
		(*itI)->Execute();
	}
}

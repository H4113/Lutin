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

bool operator<(const std::string &s1, const std::string &s2)
{
	return strcmp(s1.c_str(), s2.c_str()) < 0;
}

static void DebugContainer(const Word *w)
{
	std::cout << w << ":"<<std::endl;
	for(unsigned int i = 0; i < w->GetVal().wordContainer->size; ++i)
	{
		Word *tmp = w->GetVal().wordContainer->words[i];
		std::cout << "  (" << (int)tmp->GetSymbol() << ") " << tmp << std::endl;
	}	
}

/**
 * Program implementation
 */

Program::Program()
{
}

void Program::Build(const Word *word)
{
	WordContainer *container = word->GetVal().wordContainer;
	switch(word->GetSymbol())
	{
		case SYM_P: // Program
			std::cout << "Program with " << container->size << std::endl;
			break;

		case SYM_Pd:
			std::cout << "Declaration part with " << container->size << std::endl;
			if(container->size) // Pd -> Pd D pv
			{
				Build(container->words[0]);
				Build(container->words[1]);
			}
			return;

		case SYM_D:
			std::cout << "Decl with " << container->size << std::endl;
			Build(container->words[1]);
			return;

		case SYM_Lval:
			if(container->size == 1) // Lval -> id
			{
				std::string *value = container->words[0]->GetVal().varid;
				std::cout << "Variable with id " << *value << std::endl;

				addVariable(new Variable(*value));
			}
			else if(container->size == 3) // Lval -> Lval vg id
			{
				std::string *value = container->words[2]->GetVal().varid;
				std::cout << "Variable with id " << *value << std::endl;
				
				addVariable(new Variable(*value));
				Build(container->words[0]);
			}
			else
				std::cout << "Lval with " << container->size << std::endl;
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

				std::cout << "Constant with id " << *name << " and value " << *value << std::endl;
				
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
				std::map<std::string, Variable*>::iterator it = variables.find(*id);
				if(it == variables.end()) // Variable not found
				{
					// TODO
				}
				else
				{
					Expression *e = buildExpression(container->words[2]);
					instructions.push_back(new Assignment(it->second, e));
				}
			}
			else
			{
				Symbol firstSymbol = container->words[0]->GetSymbol();
				if(firstSymbol == SYM_w) // I -> w E
				{
					// TODO
				}
				else if(firstSymbol == SYM_r) // I -> r id
				{
					std::string *id = container->words[1]->GetVal().varid;
					std::map<std::string, Variable*>::iterator it = variables.find(*id);
					if(it == variables.end()) // Variable does not exist
					{
						// TODO
					}
					else
						instructions.push_back(new Read(it->second));
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

void Program::TestProgram(void) 
{
	Constant* lauwl = new Constant("lauwl", 4);
	Constant* prout = new Constant("prout", 40);
	Variable* hey = new Variable("hey");
	addVariable(lauwl);
	addVariable(prout);
	addVariable(hey);

	Operation* ex = new Operation(lauwl, OP_TIMES, prout, true);
	Assignment* ass = new Assignment(hey, ex);
	instructions.push_back(ass);

	std::cout << ex->Execute() << std::endl;
	std::cout << (new Read(hey))->Execute() << std::endl;
	(new Write(ex))->Execute();

	(new Read(hey))->Display();
	(new Write(ex))->Display();
}

void Program::StaticAnalysis(void)
{
	std::vector<const Variable*> vecVar;
	std::map<std::string, Variable*>::iterator itVar;
	std::set<const Variable*> varInstr;
	std::vector<Instruction*>::iterator it;
	std::set<const Variable*> diff;
	std::set<const Variable*>::iterator itDiff;

	for(it = instructions.begin(); it != instructions.end(); ++it) 
	{
		(*it)->GetVariables(varInstr);
	}

	for(itVar = variables.begin(); itVar != variables.end(); ++itVar)
	{
		vecVar.push_back(itVar->second);
	}

	//Inserts in set "diff" : varInstr - variables 
	std::set_difference(varInstr.begin(), varInstr.end(), vecVar.begin(), vecVar.end(), 
                        std::inserter(diff, diff.begin()));
	if(!diff.empty())
	{
		for(itDiff = diff.begin(); itDiff != diff.end(); ++itDiff) 
		{
			std::cerr << "ERROR : Variable "+ (*itDiff)->GetName() +" used but not declared." << std::endl;
		}
	}

	diff.clear();

	//Inserts in set "diff" : variables - varInstr
	std::set_difference(vecVar.begin(), vecVar.end(), varInstr.begin(), varInstr.end(), 
                        std::inserter(diff, diff.begin()));
	if(!diff.empty())
	{
		for(itDiff = diff.begin(); itDiff != diff.end(); ++itDiff)
		{
			std::cerr << "WARNING : Variable "+ (*itDiff)->GetName() +" not used." << std::endl;
		}
	}

}

bool Program::addVariable(Variable *variable)
{
	return variables.insert(std::pair<std::string, Variable*>(variable->GetName(), variable)).second;
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
			std::map<std::string, Variable*>::iterator it = variables.find(*id);

			if(it == variables.end()) // Variable not found
			{
				// TODO
			}
			else
				return it->second;
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
			// TODO
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


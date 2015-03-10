/**
 * Project Lutin
 */

#include <iostream>
 #include <algorithm>

#include "Program.h"
#include "Assignment.h"
#include "Operation.h"
#include "Operator.h"
#include "Read.h"
#include "Write.h"

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
			DebugContainer(word);
			break;

		case SYM_Pd:
			std::cout << "Declaration part with " << container->size << std::endl;
			DebugContainer(word);
			break;

		case SYM_D:
			std::cout << "Decl with " << container->size << std::endl;
			DebugContainer(word);
			Build(container->words[1]);
			return;

		case SYM_Lval:
			if(container->size == 1) // Lval -> id
			{
				std::string *value = container->words[0]->GetVal().varid;
				std::cout << "Variable with id " << *value << std::endl;

				variables.push_back(new Variable(*value));
			}
			else if(container->size == 3) // Lval -> Lval vg id
			{
				std::string *value = container->words[2]->GetVal().varid;
				std::cout << "Variable with id " << *value << std::endl;
				
				variables.push_back(new Variable(*value));
				Build(container->words[0]);
			}
			else
				std::cout << "Lval with " << container->size << std::endl;
			return;

		case SYM_Lconst:
			
			break;
		default:
			std::cout << "WTF ("<< (int)word->GetSymbol() << ")" << std::endl;
			return;
	}

	for(unsigned int i = 0; i < word->GetVal().wordContainer->size; ++i)
		Build(word->GetVal().wordContainer->words[i]); 
}

void Program::DisplayCode(void) 
{
	for(std::vector<Variable*>::iterator itV = variables.begin(); itV != variables.end(); ++itV)
		std::cout << (*itV)->GetDeclaration() << std::endl;
	for (std::vector<Instruction*>::iterator itI = instructions.begin() ; itI != instructions.end(); ++itI)
		(*itI)->Display();
}

void Program::TestProgram(void) 
{
	Constant* lauwl = new Constant("lauwl", 4);
	Constant* prout = new Constant("prout", 40);
	Variable* hey = new Variable("hey");
	variables.push_back(lauwl);
	variables.push_back(prout);
	variables.push_back(hey);

	Operation* ex = new Operation(lauwl, OP_TIMES, prout, true);
	Assignment* ass = new Assignment(hey, ex);
	instructions.push_back(ass);

	std::cout << ex->Execute() << std::endl;
	std::cout << (new Read(hey))->Execute() << std::endl;
	(new Write(ex))->Execute();

	(new Read(hey))->Display();
	(new Write(ex))->Display();
}

void Program::StaticAnalyser(void)
{
	std::set<const Variable*> setVar;
	std::vector<Instruction*>::iterator it;
	std::set<const Variable*> diff;

	for(it = instructions.begin(); it != instructions.end(); ++it) {
		(*it)->GetVariables(setVar);
	}
	//Inserts in set "diff" : setVar - variables 
	std::set_difference(setVar.begin(), setVar.end(), variables.begin(), variables.end(), 
                        std::inserter(diff, diff.begin()));
	if(diff.empty())
	{
		std::cerr << "Variables used but not declared" << std::endl;
	}

}

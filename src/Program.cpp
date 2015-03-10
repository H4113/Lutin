/**
 * Project Lutin
 */

#include <iostream>
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
	switch(word->GetSymbol())
	{
		case SYM_P: // Program
			std::cout << "Program with " << word->GetVal().wordContainer->size << std::endl;
			DebugContainer(word);
			break;

		case SYM_Pd:
			std::cout << "Declaration part with " << word->GetVal().wordContainer->size << std::endl;
			break;
		default:
			std::cout << "WTF ("<< (int)word->GetSymbol() << ")" << std::endl;
			DebugContainer(word);
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

	Operation* ex = new Operation(lauwl, OP_TIMES, prout);
	Assignment* ass = new Assignment(hey, ex);
	instructions.push_back(ass);

	std::cout << ex->Execute() << std::endl;
	std::cout << (new Read(hey))->Execute() << std::endl;
	(new Write(ex))->Execute();

	(new Read(hey))->Display();
	(new Write(ex))->Display();
}

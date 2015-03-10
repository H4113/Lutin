/**
 * Project Lutin
 */

#include <iostream>
#include "Program.h"
#include "Assignment.h"
#include "Operation.h"
#include "Operator.h"

/**
 * Program implementation
 */

Program::Program()
{
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

	Operation* ex = new Operation(lauwl, OP_PLUS, prout);
	Assignment* ass = new Assignment(hey, ex);
	instructions.push_back(ass);
}

void Program::StaticAnalyzer(void)
{
	std::set<const Variable*> setVar;
	std::vector<Instruction*>::iterator it;
	for(it = instructions.begin(); it != instructions.end(); ++it) {
		(*it)->GetVariables(setVar);	
	}
}

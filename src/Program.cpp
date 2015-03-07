/**
 * Project Lutin
 */


#include "Program.h"

/**
 * Program implementation
 */

Program::Program()
{
}

void Program::DisplayCode(void) 
{
	for(std::vector<Variable>::iterator itV = variables.begin(); itV != variables.end(); ++itV)
		itV->Display();
	for (std::vector<Instruction>::iterator itI = instructions.begin() ; itI != instructions.end(); ++itI)
		itI->Display();
}

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

void Program::displayCode(void) 
{
	for(std::vector<Variable>::iterator itV = variables.begin(); itV != variables.end(); ++itV)
		itV->display();
	for (std::vector<Instruction>::iterator itI = instructions.begin() ; itI != instructions.end(); ++itI)
		itI->display();
}

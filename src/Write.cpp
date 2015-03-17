/**
 * Project Lutin
 */


#include "Write.h"
#include <iostream>

/**
 * Write implementation
 */

Write::Write(Expression* e) : expression(e) 
{
	
}

void Write::Display(void) const 
{
	std::cout << ToString() << ";" << std::endl;
}

int Write::Execute(void) 
{
	int v = expression->Execute();
	std::cout << std::to_string(v) << std::endl;
	return v;
}

std::string Write::ToString(void) const 
{
	return "ecrire " + expression->ToString();
}

void Write::GetVariables(std::set<const Variable*> &set, bool) const
{
	expression->GetVariables(set);
}

InstruType Write::GetInstructionType(void) const
{
	return IT_WRI;
}

/**
 * Project Lutin
 */


#include "Variable.h"
#include <iostream>

/**
 * Variable implementation
 */


Variable::Variable(const std::string& n) : Element(), name(n)
{

}

std::string Variable::GetName(void) const 
{
	return name;
}

void Variable::Display(void) const 
{
	std::cout << ToString() << ";" << std::endl;
}

bool Variable::GetInitialized(void) const 
{
	return initialized;
}

std::string Variable::ToString(void) const 
{
	return name;
}

std::string Variable::GetDeclaration(void) const
{
	return "var " + name + ";";
}

void Variable::GetVariables(std::set<const Variable*> &set, bool) const
{
	set.insert(this);
}

InstruType Variable::GetInstructionType(void) const
{
	return IT_VAR;
}

bool Variable::IsConstant(void) const
{
	return false;
}

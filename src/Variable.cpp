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

bool Variable::IsConstant(void) const
{
	return false;
}

void Variable::GetVariables(std::set<const Variable*> &set) const
{
	set.insert(this);
}

Variable* Variable::GetModifiedVariable(void) const
{
	return this;
}

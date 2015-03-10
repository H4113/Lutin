/**
 * Project Lutin
 */


#include "Variable.h"
#include <iostream>

/**
 * Variable implementation
 */


Variable::Variable(const std::string& n) : name(n) 
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
	return "var" + name + ";";
}

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

std::string Variable::getName(void) const 
{
	return name;
}

void Variable::display(void) const 
{
	std::cout << toString() << ";" << std::endl;
}

bool Variable::getInitialized(void) const 
{
	return initialized;
}

std::string Variable::toString(void) const 
{
	return "var " + name;
}

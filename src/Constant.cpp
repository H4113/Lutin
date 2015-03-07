/**
 * Project Lutin
 */


#include "Constant.h"
#include <iostream>

/**
 * Constant implementation
 */


/**
 * @param value
 */
Constant::Constant(const std::string& n, const int& value) : Variable(n) 
{
	*pointer = value;
}

void Constant::display(void) const 
{
	std::cout << toString() << ";" << std::endl;
}

std::string Constant::toString(void) const 
{
	return "const " + name + " = " + std::to_string(*pointer);
}

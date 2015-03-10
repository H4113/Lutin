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

void Constant::Display(void) const 
{
	std::cout << ToString() << ";" << std::endl;
}

std::string Constant::GetDeclaration(void) const 
{
	return "const " + name + " = " + std::to_string(*pointer);
}

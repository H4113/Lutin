/**
 * Project Lutin
 */


#include "Value.h"
#include <iostream>

/**
 * Value implementation
 */

void Value::Display(void) const 
{
 	std::cout << ToString() << ";" << std::endl;
}

std::string Value::ToString(void) const 
{
	return std::to_string(*pointer);
}

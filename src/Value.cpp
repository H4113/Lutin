/**
 * Project Lutin
 */


#include "Value.h"
#include <iostream>

/**
 * Value implementation
 */

void Value::display(void) const 
{
 	std::cout << toString() << ";" << std::endl;
}

std::string Value::toString(void) const 
{
	return std::to_string(*pointer);
}

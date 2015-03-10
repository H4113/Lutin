/**
 * Project Lutin
 */


#include "Value.h"
#include <iostream>

/**
 * Value implementation
 */

Value::Value(bool p) : Element(p)
{

}

void Value::Display() const 
{
 	std::cout << ToString() << ";" << std::endl;
}

std::string Value::ToString(void) const 
{
	if(parenthesis)
		return "(" + std::to_string(*pointer) + ")";
	else 
		return std::to_string(*pointer);
}

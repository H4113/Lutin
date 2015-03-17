/**
 * Project Lutin
 */


#include "Value.h"
#include <iostream>

/**
 * Value implementation
 */

Value::Value() : Element()
{

}

void Value::Display() const 
{
 	std::cout << ToString() << ";" << std::endl;
}

std::string Value::ToString(void) const 
{
	return std::to_string(*pointer);
}

InstruType Value::GetInstructionType(void) const
{
	return IT_VAL;
}

/**
 * Project Lutin
 */


#include "Value.h"
#include "Utils.h"
#include <iostream>

/**
 * Value implementation
 */

Value::Value()
{
}

Value::Value(int val)
{
	value = val;
}

Value::~Value()
{
}

void Value::Display() const 
{
 	std::cout << ToString() << ";" << std::endl;
}

std::string Value::ToString(void) const 
{
	return ttos(value);
}

void Value::GetVariables(std::set<const Variable*> &set, bool) const
{
	//Does nothing
	(void)set;
}

InstruType Value::GetInstructionType(void) const
{
	return IT_VAL;
}


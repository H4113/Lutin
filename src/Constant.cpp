/**
 * Project Lutin
 */


#include "Constant.h"
#include "Utils.h"
#include <iostream>

/**
 * Constant implementation
 */


/**
 * @param value
 */
Constant::Constant(const std::string& n, const int& val):
	Variable(n) 
{
	value = val;
}

Constant::~Constant()
{
}

void Constant::Display(void) const 
{
	std::cout << ToString() << ";" << std::endl;
}

bool Constant::IsConstant(void) const
{
	return true;
}

std::string Constant::GetDeclaration(void) const 
{
	return "const " + name + " = " + ttos(value) + ";";
}

InstruType Constant::GetInstructionType(void) const
{
	return IT_CON;
}


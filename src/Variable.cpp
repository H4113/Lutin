/**
 * Project Lutin
 */

#include <iostream>

#include "Variable.h"
#include "Value.h"

/**
 * Variable implementation
 */


Variable::Variable(const std::string& n, bool g):
	name(n), ghost(g)
{
}

Variable::~Variable()
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

bool Variable::GetGhost(void) const 
{
	return ghost;
}

std::string Variable::ToString(void) const 
{
	return name;
}

std::string Variable::GetDeclaration(void) const
{
	return "var " + name + ";";
}

void Variable::GetVariables(std::set<const Variable*> &set, bool) const
{
	set.insert(this);
}

InstruType Variable::GetInstructionType(void) const
{
	return IT_VAR;
}

bool Variable::IsConstant(void) const
{
	return false;
}

Instruction *Variable::Optimize(std::map<Variable*, int> &varKnown)
{
	std::map<Variable*, int>::const_iterator it = varKnown.find(this);
	if(it != varKnown.end()) // The value is known
		return new Value(it->second);
	return this;
}


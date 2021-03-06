/**
 * Project Lutin
 */


#include "Read.h"
#include <iostream>

/**
 * Read implementation
 */

Read::Read(Variable* v):
	var(v) 
{	
}

Read::~Read()
{
}

void Read::Display(void) const 
{
	std::cout << ToString() << ";" << std::endl;
}

int Read::Execute(void) 
{
	int val;
	std::cin >> val;
	var->Set(val);
	return val;
}

std::string Read::ToString(void) const 
{
	return "lire " + var->GetName();
}

void Read::GetVariables(std::set<const Variable*> &set, bool onlyUsed) const
{
	if(!onlyUsed)
	{
		set.insert(var);
	}
}

Variable* Read::GetAssignedVar() const
{
	return var;
}

InstruType Read::GetInstructionType(void) const
{
	return IT_REA;
}

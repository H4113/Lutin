/**
 * Project Lutin
 */

#include "Assignment.h"

/**
 * Assignment implementation
 */

Assignment::Assignment(Variable* v, Expression* e) : var(v), exp(e) 
{

}

std::string Assignment::ToString(void) const 
{
	return var->ToString() + " := " + exp->ToString() + ";";
}

void Assignment::Display(void) const 
{
	std::cout << ToString() << std::endl;
}

int Assignment::Execute(void)
{
	var->Set(exp->Execute());
	return var->Get();
}

void Assignment::GetVariables(std::set<const Variable*> &set) const
{
	set.insert(var);
	exp->GetVariables(set);
}

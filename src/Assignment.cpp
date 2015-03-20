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

void Assignment::GetVariables(std::set<const Variable*> &set, bool onlyUsed) const
{
	if(!onlyUsed)
	{
		set.insert(var);
	}
	exp->GetVariables(set);
}

InstruType Assignment::GetInstructionType(void) const 
{
	return IT_ASS;
}

Variable* Assignment::GetAssignedVar() const
{
	return var;
}

Variable* Assignment::GetModifiedVariable(void) const
{
	return GetAssignedVar();
}

Expression** Assignment::GetExpression(void)
{
	return &exp;
}

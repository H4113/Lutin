/**
 * Project Lutin
 */

#include "Assignment.h"

 #include <iostream>

/**
 * Assignment implementation
 */

Assignment::Assignment(Variable* v, Expression* e):
	var(v),
	exp(e) 
{
}

Assignment::~Assignment()
{
	if(exp->MayBeDeleted())
		delete exp;
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

void Assignment::SetExpression(Expression *e)
{
	if(e == exp)
		return;
	if(exp != 0 && exp->MayBeDeleted())
		delete exp;
	exp = e;
}

Expression* Assignment::GetExpression(void)
{
	return exp;
}

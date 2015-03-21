#include <iostream>

#include "NestedExpression.h"

NestedExpression::NestedExpression(Expression *e):
	expression(e)
{
}

NestedExpression::~NestedExpression()
{
	if(expression->MayBeDeleted())
		delete expression;
}

int NestedExpression::Execute(void)
{
	return expression->Execute();
}
		
void NestedExpression::Display(void) const
{
	std::cout << ToString() << std::endl;
}

std::string NestedExpression::ToString(void) const
{
	return std::string("(") + expression->ToString() + std::string(")");
}

void NestedExpression::GetVariables(std::set<const Variable*> &set, bool) const
{
	expression->GetVariables(set);
}

InstruType NestedExpression::GetInstructionType(void) const 
{
	return IT_NES;
}

Expression** NestedExpression::GetExpression(void)
{
	return &expression;
}

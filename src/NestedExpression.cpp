#include <iostream>

#include "NestedExpression.h"

NestedExpression::NestedExpression(Expression *e):
	expression(e)
{
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


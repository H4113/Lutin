/**
 * Project Lutin
 */


#include "Write.h"
#include <iostream>

/**
 * Write implementation
 */

Write::Write(Expression* e):
	expression(e) 
{
	
}

Write::~Write()
{
	if(expression->MayBeDeleted())
		delete expression;
}

void Write::Display(void) const 
{
	std::cout << ToString() << ";" << std::endl;
}

int Write::Execute(void) 
{
	int v = expression->Execute();
	std::cout << std::to_string(v) << std::endl;
	return v;
}

std::string Write::ToString(void) const 
{
	return "ecrire " + expression->ToString();
}

void Write::GetVariables(std::set<const Variable*> &set, bool) const
{
	expression->GetVariables(set);
}

InstruType Write::GetInstructionType(void) const
{
	return IT_WRI;
}

void Write::SetExpression(Expression *e)
{
	if(e == expression)
		return;
	if(expression != 0 && expression->MayBeDeleted())
		delete expression;
	expression = e;
}

Expression* Write::GetExpression(void)
{
	return expression;
}

Instruction *Write::Optimize(std::map<Variable*, int> &varKnown)
{
	Instruction *inst = expression->Optimize(varKnown);
	if(inst != expression)
	{
		if(expression->MayBeDeleted())
			delete expression;
		expression = static_cast<Expression*>(inst);
	}
	return this;
}


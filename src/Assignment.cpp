/**
 * Project Lutin
 */

#include "Assignment.h"

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

Instruction *Assignment::Optimize(std::map<Variable*, int> &varKnown)
{
	Expression *inst = static_cast<Expression*>(exp->Optimize(varKnown));
	InstruType type = inst->GetInstructionType();

	if(inst != exp)
	{
		if(exp->MayBeDeleted())
			delete exp;
		exp = inst;
	}

	if(type == IT_VAL || type == IT_VAR || type == IT_CON)
		varKnown[var] = inst->Execute();

	return this;
}


/**
 * Project Lutin
 */


#include "Operation.h"

/**
 * Operation implementation
 */

Operation::Operation(Expression* e1, Operator o, Expression* e2):
	exp1(e1),
	exp2(e2),
	op(o)
{
}

Operation::~Operation()
{
	if(exp1->MayBeDeleted())
		delete exp1;
	if(exp2->MayBeDeleted())
		delete exp2;	
}

void Operation::Display(void) const {
	std::cout << ToString() << ";" << std::endl;
}

std::string Operation::ToString(void) const 
{
	std::string oper;
	switch(op) 
	{
		case OP_PLUS:
			oper = "+";
			break;
		case OP_MINUS:
			oper = "-";
			break;
		case OP_DIVIDE:
			oper = "/";
			break;
		case OP_TIMES:
			oper = "*";
			break;
		default: // dead code
			oper = "?";
			break;
	}
	return exp1->ToString() + " " + oper + " " + exp2->ToString();
}

int Operation::Execute(void) 
{
	switch(op) 
	{
		case OP_PLUS:
			//std::cout << exp1->Execute() << "+" << exp2->Execute() << std::endl;
			return exp1->Execute() + exp2->Execute();
			break;
		case OP_MINUS:
			//std::cout << exp1->Execute() << "-" << exp2->Execute() << std::endl;
			return exp1->Execute() - exp2->Execute();
			break;
		case OP_DIVIDE:
			//std::cout << exp1->Execute() << "/" << exp2->Execute() << std::endl;
			return exp1->Execute() / exp2->Execute();
			break;
		case OP_TIMES:
			//std::cout << exp1->Execute() << "*" << exp2->Execute() << std::endl;
			return exp1->Execute() * exp2->Execute();
			break;
		default: // dead code
			return 0;
			break;
	}
}

void Operation::GetVariables(std::set<const Variable*> &set, bool) const
{
	exp1->GetVariables(set);
	exp2->GetVariables(set);
}

InstruType Operation::GetInstructionType(void) const
{
	return IT_OPE;
}

void Operation::SetExp1(Expression *e)
{
	if(e == exp1)
		return;
	if(exp1 != 0 && exp1->MayBeDeleted())
		delete exp1;
	exp1 = e;
}

Expression* Operation::GetExp1(void)
{
	return exp1;
}

void Operation::SetExp2(Expression *e)
{
	if(e == exp2)
		return;
	if(exp2 != 0 && exp2->MayBeDeleted())
		delete exp2;
	exp2 = e;
}

Expression* Operation::GetExp2(void)
{
	return exp2;
}

Operator Operation::GetOperator(void) const
{
	return op;
}

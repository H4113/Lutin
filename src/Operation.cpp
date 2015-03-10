/**
 * Project Lutin
 */


#include "Operation.h"

/**
 * Operation implementation
 */

Operation::Operation(Expression* e1, Operator o, Expression* e2) :
	exp1(e1), exp2(e2), op(o)
{

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
		case OP_DIVIDED:
			oper = "/";
			break;
		case OP_TIMES:
			oper = "*";
			break;
		default: // dead code
			oper = "+";
			break;
	}
	return exp1->ToString() + " " + oper + " " + exp2->ToString();
}

int Operation::Execute(void) 
{
	switch(op) 
	{
		case OP_PLUS:
			return exp1->Execute() + exp2->Execute();
			break;
		case OP_MINUS:
			return exp1->Execute() - exp2->Execute();
			break;
		case OP_DIVIDED:
			return exp1->Execute() / exp2->Execute();
			break;
		case OP_TIMES:
			return exp1->Execute() * exp2->Execute();
			break;
		default: // dead code
			return exp1->Execute() + exp2->Execute();
			break;
	}
}

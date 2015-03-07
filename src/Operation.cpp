/**
 * Project Lutin
 */


#include "Operation.h"

/**
 * Operation implementation
 */

void Operation::Display(void) const {
	std::cout << ToString() << ";" << std::endl;
}

std::string Operation::ToString(void) const 
{
	std::string oper;
	switch(op) 
	{
		case PLUS:
			oper = "+";
			break;
		case MINUS:
			oper = "-";
			break;
		case DIVIDED:
			oper = "/";
			break;
		case TIMES:
			oper = "*";
			break;
		default: // dead code
			oper = "+";
			break;
	}
	return exp1->ToString() + oper + exp2->ToString();
}

int Operation::Execute(void) 
{
	switch(op) 
	{
		case PLUS:
			return exp1->Execute() + exp2->Execute();
			break;
		case MINUS:
			return exp1->Execute() - exp2->Execute();
			break;
		case DIVIDED:
			return exp1->Execute() / exp2->Execute();
			break;
		case TIMES:
			return exp1->Execute() * exp2->Execute();
			break;
		default: // dead code
			return exp1->Execute() + exp2->Execute();
			break;
	}
}

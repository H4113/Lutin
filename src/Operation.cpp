/**
 * Project Lutin
 */


#include "Operation.h"

/**
 * Operation implementation
 */

Operation::Operation(Expression* e1, Operator o, Expression* e2) :
	Expression(), exp1(e1), exp2(e2), op(o)
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
	//std::cout << ToString() << " | ";
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

Expression* Operation::GetExp1(void) const
{
	return exp1;
}

Expression* Operation::GetExp2(void) const
{
	return exp2;
}

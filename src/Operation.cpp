/**
 * Project Lutin
 */


#include "Operation.h"
#include "Value.h"

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
	if(exp1 != 0 && exp1->MayBeDeleted())
		delete exp1;
	if(exp2 != 0 && exp2->MayBeDeleted())
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

Instruction *Operation::Optimize(std::map<Variable*, int> &varKnown)
{
	Expression *inst1 = static_cast<Expression*>(exp1->Optimize(varKnown));
	Expression *inst2 = static_cast<Expression*>(exp2->Optimize(varKnown));
	
	InstruType type1 = inst1->GetInstructionType();
	InstruType type2 = inst2->GetInstructionType();
	
	bool const1 = (type1 == IT_CON || type1 == IT_VAL);
	bool const2 = (type2 == IT_CON || type2 == IT_VAL);

	if(inst1 != exp1)
	{
		if(exp1->MayBeDeleted())
			delete exp1;
		exp1 = inst1;
	}
	if(inst2 != exp2)
	{
		if(exp2->MayBeDeleted())
			delete exp2;
		exp2 = inst2;
	}

	if(type1 == IT_VAL && type2 == IT_VAL)
	{
		int v = Execute();
		if(exp1->MayBeDeleted())
			delete exp1;
		if(exp2->MayBeDeleted())
			delete exp2;
		exp1 = 0;
		exp2 = 0;
		return new Value(v);
	}

	switch(op)
	{
		case OP_PLUS:
			if(exp1->Execute() == 0 && const1)
			{
				if(exp1->MayBeDeleted())
					delete exp1;
				exp1 = 0;
				exp2->Protect();
				return exp2;
			}
			else if(exp2->Execute() == 0 && const2)
			{
				if(exp2->MayBeDeleted())
					delete exp2;
				exp2 = 0;
				exp1->Protect();
				return exp1;
			}
			break;

		case OP_MINUS:
			if(exp2->Execute() == 0 && const2)
			{
				if(exp2->MayBeDeleted())
					delete exp2;
				exp2 = 0;
				exp1->Protect();
				return exp1;
			}
			break;

		case OP_DIVIDE:
			if(exp2->Execute() == 1 && const2)
			{
				if(exp2->MayBeDeleted())
					delete exp2;
				exp2 = 0;
				exp1->Protect();
				return exp1;
			}
			break;

		case OP_TIMES:
			if(exp1->Execute() == 1 && const1)
			{
				if(exp1->MayBeDeleted())
					delete exp1;
				exp1 = 0;
				exp2->Protect();
				return exp2;
			}
			else if(exp2->Execute() == 1 && const2)
			{
				if(exp2->MayBeDeleted())
					delete exp2;
				exp2 = 0;
				exp1->Protect();
				return exp1;
			}
			break;
		default:
			break;
	}

	return this;
}


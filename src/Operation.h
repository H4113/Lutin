/**
 * Project Lutin
 */


#ifndef _OPERATION_H
#define _OPERATION_H

#include "Expression.h"
#include "Expression.h"
#include "Operator.h"


class Operation: public Expression {
	public:
		Operation();
	private: 
		Expression expressions;
		Operator op;
};

#endif //_OPERATION_H

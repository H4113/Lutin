/**
 * Project Lutin
 */


#ifndef _OPERATION_H
#define _OPERATION_H

#include "Expression.h"
#include "Expression.h"
#include "Operator.h"


class Operation: public Expression {
private: 
	Expression expressions;
	Operator operator;
};

#endif //_OPERATION_H
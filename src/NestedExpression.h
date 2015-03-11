/**
 * Project Lutin
 */


#ifndef _NESTEDEXPRESSION_H
#define _NESTEDEXPRESSION_H

#include "Expression.h"

class NestedExpression : public Expression
{
	public:
		NestedExpression(Expression *e);

		virtual int Execute(void);
		
		virtual void Display(void) const;

		virtual std::string ToString(void) const;

		virtual void GetVariables(std::set<const Variable*> &set) const;
	protected:
		Expression *expression;
};

#endif //_NESTEDEXPRESSION_H


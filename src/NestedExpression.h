/**
 * Project Lutin
 */


#ifndef _NESTEDEXPRESSION_H
#define _NESTEDEXPRESSION_H

#include "Expression.h"

/**
 *	@class NestedExpression
 *  @brief An expression between parentheses
 */
class NestedExpression : public Expression
{
	public:
		NestedExpression(Expression *e);
		virtual ~NestedExpression();

		virtual int Execute(void);
		
		virtual void Display(void) const;

		virtual std::string ToString(void) const;

		virtual void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const;

		void SetExpression(Expression *e);
		Expression* GetExpression(void);

		//@Override
		InstruType GetInstructionType(void) const;
	protected:
		Expression* expression;
};

#endif //_NESTEDEXPRESSION_H


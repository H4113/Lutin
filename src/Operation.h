/**
 * Project Lutin
 */


#ifndef _OPERATION_H
#define _OPERATION_H

#include "Expression.h"
#include "Expression.h"
#include "Operator.h"
#include <iostream>

class Operation: public Expression 
{
	public:
		Operation(Expression*, Operator, Expression*);

		virtual ~Operation();
		/**
		 *	Display the code corresponding to the operation instruction.
		 */ 
		void Display(void) const;

		/**
		 *	Execute the operation instruction.
		 *	@return the computed value
		 */ 
		int Execute(void);

		/**
		 *	Creates a string representing the operation instruction
		 *	@return the string created
		 */
		std::string ToString(void) const;

		//Override
		void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const;

		//@Override
		InstruType GetInstructionType(void) const;

		Expression** GetExp1(void);

		Expression** GetExp2(void);

		Operator GetOperator(void) const;
	private: 
		Expression* exp1;
		Expression* exp2;
		Operator op;
};

#endif //_OPERATION_H

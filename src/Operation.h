/**
 * Project Lutin
 */


#ifndef _OPERATION_H
#define _OPERATION_H

#include "Expression.h"
#include "Expression.h"
#include "Operator.h"
#include <iostream>

class Operation: public Expression {
	public:
		Operation();
		/**
		 *	Display the code corresponding to the operation instruction.
		 */ 
		void display() const;

		/**
		 *	Execute the operation instruction.
		 *	@return the computed value
		 */ 
		int execute();

		/**
		 *	Creates a string representing the operation instruction
		 *	@return the string created
		 */
		std::string toString() const;
	private: 
		Expression* exp1;
		Expression* exp2;
		Operator op;
};

#endif //_OPERATION_H

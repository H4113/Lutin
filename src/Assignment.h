/**
 * Project Lutin
 */


#ifndef _ASSIGNMENT_H
#define _ASSIGNMENT_H

#include "Instruction.h"
#include "Variable.h"
#include "Expression.h"
#include <iostream>

/**
 *	@class Assignement
 *	Instruction allowing to assign a value to a variable
 */
class Assignment: public Instruction {
	public:
		/**
		 *	Display the code corresponding to the assignment instruction.
		 */ 
		void display() const;

		/**
		 *	Execute the assignment instruction.
		 *	@return the assigned value
		 */ 
		int execute();

		/**
		 *	Creates a string representing the assignment instruction
		 *	@return the string created
		 */
		std::string toString() const;
	private:
		// The variable to be assigned
		Variable* var;
		// The expression to assign to the variable
		Expression* exp;
};

#endif //_ASSIGNMENT_H

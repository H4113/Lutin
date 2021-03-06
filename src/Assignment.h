/**
 * Project Lutin
 */


#ifndef _ASSIGNMENT_H
#define _ASSIGNMENT_H

#include "Instruction.h"
#include "Variable.h"
#include "Expression.h"
#include <string>
#include <set>

/**
 *	@class Assignment
 *	@brief Instruction allowing to assign a value to a variable
 */
class Assignment: public Instruction 
{
	public:
		Assignment(Variable*, Expression*);
		virtual ~Assignment();

		/**
		 *	Display the code corresponding to the assignment instruction.
		 */ 
		void Display(void) const;

		/**
		 *	Execute the assignment instruction.
		 *	@return the assigned value
		 */ 
		int Execute(void);

		/**
		 *	Creates a string representing the assignment instruction
		 *	@return the string created
		 */
		std::string ToString(void) const;

		//@Override
		InstruType GetInstructionType(void) const;
		
		void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const;

		//Override
		Variable* GetAssignedVar() const;

		void SetExpression(Expression *e);
		Expression* GetExpression(void);
	private:
		// The variable to be assigned
		Variable* var;
		// The expression to assign to the variable
		Expression* exp;
};

#endif //_ASSIGNMENT_H

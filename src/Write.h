/**
 * Project Lutin
 */


#ifndef _WRITE_H
#define _WRITE_H

#include "Instruction.h"
#include "Expression.h"
#include <string>
#include <set>


class Write: public Instruction 
{
	public:
		Write(Expression*);
		virtual ~Write();

		/**
		 *	Display the code corresponding to the write instruction.
		 */ 
		void Display(void) const;

		/**
		 *	Execute the write instruction.
		 *	@return the writen value
		 */ 
		int Execute(void);

		/**
		 *	Creates a string representing the write instruction
		 *	@return the string created
		 */
		std::string ToString(void) const;

		//Override
		void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const;

		//@Override
		InstruType GetInstructionType(void) const;

		void SetExpression(Expression *e);
		Expression* GetExpression(void);

	private: 
		Expression* expression;
};

#endif //_WRITE_H

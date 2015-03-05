/**
 * Project Lutin
 */


#ifndef _WRITE_H
#define _WRITE_H

#include "Instruction.h"
#include "Expression.h"


class Write: public Instruction {
	public:
		/**
		 *	Display the code corresponding to the write instruction.
		 */ 
		void display() const;

		/**
		 *	Execute the write instruction.
		 *	@return the writen value
		 */ 
		int execute();

		/**
		 *	Creates a string representing the write instruction
		 *	@return the string created
		 */
		std::string toString() const;
	private: 
		Expression* expression;
};

#endif //_WRITE_H

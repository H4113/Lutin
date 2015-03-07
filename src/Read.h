/**
 * Project Lutin
 */


#ifndef _READ_H
#define _READ_H

#include "Instruction.h"
#include "Variable.h"
#include <iostream>

class Read: public Instruction {
	public:
		Read(Variable*);

		/**
		 *	Display the code corresponding to the read instruction.
		 */ 
		void display() const;

		/**
		 *	Execute the read instruction.
		 *	@return the read value
		 */ 
		int execute();

		/**
		 *	Creates a string representing the read instruction
		 *	@return the string created
		 */
		std::string toString() const;
	private: 
		Variable* var;
};

#endif //_READ_Hvi

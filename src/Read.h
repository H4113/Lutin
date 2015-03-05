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
		int execute();

		void display() const;

		/**
		 *	Creates a string representing the read instruction
		 *	@return the string created
		 */
		std::string toString() const;
	private: 
		Variable* var;
};

#endif //_READ_Hvi

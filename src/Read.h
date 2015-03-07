/**
 * Project Lutin
 */


#ifndef _READ_H
#define _READ_H

#include "Instruction.h"
#include "Variable.h"
#include <iostream>

class Read: public Instruction 
{
	public:
		Read(Variable*);

		/**
		 *	Display the code corresponding to the read instruction.
		 */ 
		void Display(void) const;

		/**
		 *	Execute the read instruction.
		 *	@return the read value
		 */ 
		int Execute(void);

		/**
		 *	Creates a string representing the read instruction
		 *	@return the string created
		 */
		std::string ToString(void) const;
	private: 
		Variable* var;
};

#endif //_READ_Hvi

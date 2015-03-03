/**
 * Project Lutin
 */


#ifndef _PROGRAM_H
#define _PROGRAM_H

#include <vector>

#include "Instruction.h"
#include "Variable.h"


class Program {
	public:
		Program();

		void displayCode();
		
	private: 
		std::vector<Instruction> instructions;
		std::vector<Variable> variables;
};

#endif //_PROGRAM_H

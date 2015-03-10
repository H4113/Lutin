/**
 * Project Lutin
 */


#ifndef _PROGRAM_H
#define _PROGRAM_H

#include <vector>

#include "Instruction.h"
#include "Variable.h"
#include "Constant.h"


class Program 
{
	public:
		Program();

		void DisplayCode(void);

		void TestProgram(void);

		void CloseTestProgram(void);
		
	private: 
		std::vector<Instruction*> instructions;
		std::vector<Variable*> variables;
};

#endif //_PROGRAM_H

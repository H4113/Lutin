/**
 * Project Lutin
 */


#ifndef _PROGRAM_H
#define _PROGRAM_H

#include <vector>
#include <set>
#include <iterator>

#include "Instruction.h"
#include "Variable.h"
#include "Constant.h"


class Program 
{
	public:
		Program();

		void DisplayCode(void);

		void TestProgram(void);

		/*
		* Does a static analysis of the program 
		*/
		void StaticAnalyzer(void);

		void CloseTestProgram(void);
		
	private: 
		std::vector<Instruction*> instructions;
		std::vector<Variable*> variables;
};

#endif //_PROGRAM_H

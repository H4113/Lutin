/**
 * Project Lutin
 */


#ifndef _PROGRAM_H
#define _PROGRAM_H

#include <string>
#include <vector>
#include <map>

#include "Instruction.h"
#include "Variable.h"
#include "Constant.h"
#include "Word.h"

bool operator<(const std::string &s1, const std::string &s2);

class Program 
{
	public:
		Program();

		void Build(const Word *p);
		void DisplayCode(void);

		void TestProgram(void);

		/*
		* Does a static analysis of the program 
		*/
		void StaticAnalysis(void);

		void CloseTestProgram(void);
		
	private:
		bool addVariable(Variable *variable);

		std::vector<Instruction*> instructions;
		std::map<std::string, Variable*> variables;
};

#endif //_PROGRAM_H

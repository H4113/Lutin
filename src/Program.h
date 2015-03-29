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
#include "NestedExpression.h"
#include "Operation.h"

bool operator<(const std::string &s1, const std::string &s2);

/**
 *	@class Program
 *  @brief Contains all declarations and instructions of the program.
 */
class Program 
{
	public:
		Program();
		virtual ~Program();

		void Build(const Word *word);
		void DisplayCode(void);

		/*
		* Does a static analysis of the program 
		*/
		void StaticAnalysis(void);

		void Optimize(void);

		void Execute(void);
		
	private:
		bool addVariable(Variable *variable);
		Variable *getGrammarVariable(const std::string &id);
		Expression *buildExpression(const Word *w);
		void Optimize(Instruction*, std::map<Variable*, int> & varKnown);
		Expression *Optimize(Expression*, std::map<Variable*, int> & varKnown);

		std::vector<Instruction*> instructions;
		std::map<std::string, Variable*> variables;
};

#endif //_PROGRAM_H

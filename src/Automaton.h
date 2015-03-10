/**
 * Project Lutin
 */


#ifndef _AUTOMATON_H
#define _AUTOMATON_H

#include "State.h"
#include "Program.h"
#include "LexicalAnalyzer.h"
#include "Word.h"
#include "Symbol.h"

#include <iostream>
#include <stack>

/**
 *	@class Automaton
 */
class Automaton 
{
	public:
		Automaton();
		virtual ~Automaton();

		void Read(std::istream &stream);

		void Shift(Word *word, State *state);
		StateResult Reduce(Word *word, unsigned int ruleId);

		void TestAutomaton(void);

		void CloseTestProgram(void);

	private:
		Program program;
		LexicalAnalyzer analyzer;
		std::stack<const Word*> words;
		std::stack<State*> states;
};

#endif //_AUTOMATON_H

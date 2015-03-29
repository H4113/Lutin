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
 *  @brief An automaton to parse the language 
 */
class Automaton 
{
	public:
		Automaton();
		virtual ~Automaton();

		Word *Read(std::istream &stream);

		void Shift(Word *word, State *state);
		StateResult Reduce(unsigned int ruleId);

	private:
		void pushWord(Word *word);

		LexicalAnalyzer analyzer;
		std::stack<Word*> words;
		std::stack<State*> states;
};

#endif //_AUTOMATON_H

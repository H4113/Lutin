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
#include <vector>
#include <stack>

/**
 *	@class Automaton
 */
class Automaton {
	public:
		Automaton();
		virtual ~Automaton();

		void Read(std::istream &stream);

		void Shift(const Symbol &symbol, State *state);
		void Reduce(void);

	private:
		Program program;
		LexicalAnalyzer analyzer;
		std::vector<Word> words;
		std::stack<Symbol> symbols;
		std::stack<State*> states;
};

#endif //_AUTOMATON_H

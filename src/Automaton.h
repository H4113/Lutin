/**
 * Project Lutin
 */


#ifndef _AUTOMATON_H
#define _AUTOMATON_H

#include "State.h"
#include "Program.h"
#include "LexicalAnalyzer.h"
#include "Word.h"

#include <vector>
#include <stack>


class Automaton {
	public:
	private:
		Program program;
		LexicalAnalyzer analyzer;
		std::vector<Word> words;
		std::stack<State*> states;
};

#endif //_AUTOMATON_H

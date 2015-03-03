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


class Automaton {
	public: 
		State* state;
	private: 
		Program program;
		LexicalAnalyzer analyzer;
		std::vector<Word> words;
};

#endif //_AUTOMATON_H
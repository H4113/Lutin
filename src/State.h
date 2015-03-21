/**
 * Project Lutin
 */


#ifndef _STATE_H
#define _STATE_H

#include <vector>

#include "Word.h"

class Automaton;

enum StateResult 
{
	SR_TRANSITION,
	SR_ACCEPT,
	SR_ERROR
};

class State {
	public: 
		State();
		virtual ~State();

		/**
		 * @param automaton
		 * @param word
		 */
		virtual StateResult Transition(Automaton* automaton, Word *word) = 0;
		const std::vector<Symbol> &GetExpectedTerminals(void) const;

	protected:
		std::vector<Symbol> expectedTerminals;
};

#endif //_STATE_H

/**
 * Project Lutin
 */


#ifndef _STATE_H
#define _STATE_H

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
		
		/**
		 * @param automaton
		 * @param word
		 */
		virtual StateResult Transition(Automaton* automaton, Word *word) = 0;
};

#endif //_STATE_H

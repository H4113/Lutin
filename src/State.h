/**
 * Project Lutin
 */


#ifndef _STATE_H
#define _STATE_H

#include "Word.h"

class Automaton;

class State {
	public: 
		
		/**
		 * @param automaton
		 * @param word
		 */
		virtual void Transition(Automaton* automaton, const Word *word) = 0;
};

#endif //_STATE_H

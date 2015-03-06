/**
 * Project Lutin
 */


#ifndef _STATE_H
#define _STATE_H

#include "Symbol.h"

class Automaton;

class State {
	public: 
		
		/**
		 * @param automaton
		 * @param symbol
		 */
		virtual void Transition(Automaton* automaton, const Symbol& symbol) = 0;
};

#endif //_STATE_H

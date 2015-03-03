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
		 * @param automate
		 * @param symbol
		 */
		virtual void transition(const Automaton* automate, const Symbol& symbol) = 0;
};

#endif //_STATE_H

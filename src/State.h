/**
 * Project Lutin
 */


#ifndef _STATE_H
#define _STATE_H

#include "Automaton.h"
#include "Symbol.h"

class State {
public: 
	
	/**
	 * @param automate
	 * @param symbol
	 */
	void transition(Automaton& automate, Symbol& symbol);
};

#endif //_STATE_H

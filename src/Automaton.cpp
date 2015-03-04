/**
 * Project Lutin
 */


#include "Automaton.h"

/**
 * Automaton implementation
 */

Automaton::Automaton()
{
}

Automaton::~Automaton()
{
}

void Automaton::Shift(const Symbol &symbol, State *state)
{
	symbols.push(symbol);
	states.push(state);
}

void Automaton::Reduce(void)
{
	// TODO
}


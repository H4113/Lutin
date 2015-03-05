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

void Automaton::Read(std::istream &stream)
{
	char c;

	while(stream.get(c))
	{
		std::cout << c << std::endl;
	}
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


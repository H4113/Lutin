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

void Automaton::Shift(const Word *word, State *state)
{
	words.push(word);
	states.push(state);
}

void Automaton::Reduce(void)
{
	// TODO
}


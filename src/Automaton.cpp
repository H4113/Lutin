/**
 * Project Lutin
 */


#include "Automaton.h"
#include "Rules.h"

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

void Automaton::Shift(Word *word, State *state)
{
	words.push(word);
	states.push(state);
}

void Automaton::Reduce(Word *word, unsigned int ruleId)
{
	const Rule &rule = RULES[ruleId];
	State *currentState;

	// First pop all right value symbols
	for(unsigned int i = 0; i < rule.rightPartCount; ++i)
	{
		delete states.top();
		states.pop();
	}

	currentState = states.top();

	// Then, build the new world (ie. change the symbol)
	word->SetSymbol(rule.leftPart);

	// Finally, evaluate the next state
	currentState->Transition(this, word);
}


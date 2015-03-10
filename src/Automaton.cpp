/**
 * Project Lutin
 */


#include "Automaton.h"
#include "Rules.h"
#include "ConcreteStates.h"

/**
 * Automaton implementation
 */

Automaton::Automaton()
{
	states.push(new State00());
}

Automaton::~Automaton()
{
	while(states.size() != 0)
	{
		delete states.top();
		states.pop();
	}
}

void Automaton::Read(std::istream &stream)
{
	analyzer.SetInputStream(&stream);
	Word *w;
	bool error = false;

	while(!analyzer.Eof())
	{
		w = analyzer.ReadNextWord();
		if(w == 0) {
			continue;
		}
		Word::DebugWord(w);
		
		switch(states.top()->Transition(this, w))
		{
			case SR_TRANSITION: // Ok
				break;
			case SR_ACCEPT: // Should not happen
				break;
			default:
				std::cerr << "Error at line " << analyzer.GetCurrentLine()
						  << ":" << analyzer.GetCurrentCharacter() << std::endl;
				error = true;
				break;
		}
		delete w;
	}
}

void Automaton::Shift(Word *word, State *state)
{
	std::cout << "Shift" << std::endl;
	words.push(word);
	states.push(state);
}

StateResult Automaton::Reduce(Word *word, unsigned int ruleId)
{
	const Rule &rule = RULES[ruleId];
	State *currentState;

	std::cout << "Reducing " << rule.rightPartCount << " states (r" << ruleId << ")" << std::endl;

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
	return currentState->Transition(this, word);
}

void Automaton::Transform()
{
	std::cerr << "Transformation du programme" << std::endl;
}
void Automaton::StaticAnalysis()
{
	std::cerr << "Analyse statique du programme" << std::endl;
}
void Automaton::Execute()
{
	std::cerr << "Execution du programme" << std::endl;
}
void Automaton::Print()
{
	std::cerr << "Affichage du code" << std::endl;
}
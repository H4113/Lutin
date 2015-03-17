/**
 * Project Lutin
 */


#include "Automaton.h"
#include "Rules.h"
#include "ConcreteStates.h"
#include "user.h"

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

Word *Automaton::Read(std::istream &stream)
{
	analyzer.SetInputStream(&stream);
	Word *w;
	bool error = false;
	bool done = false;

	while(!done)
	{
		w = analyzer.GetCurrentWord();
		if(w == 0) {
			continue;
		}
#ifdef DEBUG
		Word::DebugWord(w);
#endif
	
		switch(states.top()->Transition(this, w))
		{
			case SR_TRANSITION: // Ok
				break;
			case SR_ACCEPT:
				done = true;
#ifdef DEBUG
				std::cout << "*-----PROGRAM ACCEPTED-----*" << std::endl;
#endif

				break;
			default:
				//Needed to avoid infinite loop
				if(w->GetSymbol() == SYM_end)
				{
					done = true;
				}
				else
				{
					Word::DebugWord(w);
					std::cerr << "Erreur syntaxique " << analyzer.GetCurrentLine()
							  << ":" << analyzer.GetCurrentCharacter() << std::endl;
					error = true;
					analyzer.Shift();
				}
				break;
		}
	}

	if(done)
		return words.top();
	return 0;
}

void Automaton::Shift(Word *word, State *state)
{
#ifdef DEBUG
	std::cout << "Shift" << std::endl;	
#endif	

	if(word->GetSymbol() != SYM_end)
		states.push(state);

	if(IsTerminal(word->GetSymbol()))
	{
		pushWord(word);
		analyzer.Shift();
	}
}

StateResult Automaton::Reduce(Word *word, unsigned int ruleId)
{
	const Rule &rule = RULES[ruleId];
	State *currentState;
	StateResult result;
	Word *newWord;
	UWordVal val;

#ifdef DEBUG
	std::cout << "Reducing " << rule.rightPartCount << " states (r" << ruleId << ")" << std::endl;
#endif

	val.wordContainer = new WordContainer;
	if(rule.rightPartCount > 0)
		val.wordContainer->words = new Word*[rule.rightPartCount];
	else
		val.wordContainer->words = 0;
	val.wordContainer->size = rule.rightPartCount; 
	
	// First pop all right value symbols
	for(unsigned int i = 0; i < rule.rightPartCount; ++i)
	{
		delete states.top();
		states.pop();

		val.wordContainer->words[rule.rightPartCount-1-i] = words.top();
		words.pop();
	}

	currentState = states.top();

	newWord = new Word(rule.leftPart, val);
	pushWord(newWord);

	// Make the transition with the non-terminal symbol
	result = currentState->Transition(this, newWord);
		
	return result;  
}

void Automaton::TestAutomaton(void) 
{
	//program.TestProgram();
	//program.DisplayCode();
}


void Automaton::pushWord(Word *word)
{
	if(word->GetSymbol() != SYM_end)
		words.push(word);
}


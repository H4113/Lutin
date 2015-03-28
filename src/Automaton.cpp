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
		if(w == 0)
			continue;
		
#ifdef DEBUG
		Word::DebugWord(w);
#endif
	
		switch(states.top()->Transition(this, w))
		{
			case SR_TRANSITION: // Ok
				error = false;
				break;
			case SR_ACCEPT:
				done = true;
				error = false;
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
					if(!error)
					{
						const std::vector<Symbol> &expected = states.top()->GetExpectedTerminals(); 
						std::cerr << "Syntax error (" << analyzer.GetCurrentLine()
								  << ":" << analyzer.GetCurrentCharacter() << ") ";
						
						for(unsigned int i = 0; i < expected.size(); ++i)
						{
							std::string name = SymbolToString(expected[i]);
							std::cerr << name;
							if(i+1 != expected.size())
								std::cerr << " or ";
						}
						std::cerr << " expected" << std::endl;
					}
					analyzer.Shift();
					delete w;
					w = 0;
				}
				error = true;
				break;
		}

		if(w != 0 && w->GetSymbol() == SYM_end)
			delete w;
	}

	if(!error && !analyzer.HasError())
	{
#ifdef DEBUG
		std::cout << words.size() << " ord kvar" << std::endl;
#endif	
		return words.top();
	}

	while(words.size())
	{
		delete words.top();
		words.pop();
	}

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

StateResult Automaton::Reduce(unsigned int ruleId)
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

void Automaton::pushWord(Word *word)
{
	if(word->GetSymbol() != SYM_end)
		words.push(word);
}


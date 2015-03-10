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
		Word::DebugWord(w);
		
		switch(states.top()->Transition(this, w))
		{
			case SR_TRANSITION: // Ok
				break;
			case SR_ACCEPT:
				done = true;
				std::cout << "*-----PROGRAM ACCEPTED-----*" << std::endl;
				break;
			default:
				std::cerr << "Error at line " << analyzer.GetCurrentLine()
						  << ":" << analyzer.GetCurrentCharacter() << std::endl;
				//Needed to avoid infinite loop
				if(w->GetSymbol() == SYM_end)
				{
					done = true;
				}
				error = true;
				analyzer.Shift();
				break;
		}
	}

	if(done)
		return words.top();
	return 0;
}

void Automaton::Shift(Word *word, State *state)
{
	std::cout << "Shift" << std::endl;	
	words.push(word);
	states.push(state);

	if(IsTerminal(word->GetSymbol())){
		std::cout << "word consumed" << std::endl;
		analyzer.Shift();
	}
}

StateResult Automaton::Reduce(Word *word, unsigned int ruleId)
{
	const Rule &rule = RULES[ruleId];
	State *currentState;
	Symbol prevSymbol = word->GetSymbol();
	StateResult result;
	Word *newWord;
	UWordVal val;

	std::cout << "Reducing " << rule.rightPartCount << " states (r" << ruleId << ")" << std::endl;

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
	words.push(newWord);

	// Then, build the new word (ie. change the symbol)
	//word->SetSymbol(rule.leftPart);
	// Make the transition with the non-terminal symbol
	result = currentState->Transition(this, newWord);
		

	Word::DebugWord(newWord);

	// Reset the word with the previous terminal symbol
	//word->SetSymbol(prevSymbol);
	// Finally, evaluate the next state
	return result;  
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

void Automaton::TestAutomaton(void) 
{
	//program.TestProgram();
	//program.DisplayCode();
}


/**
 * Project Lutin
 */


#include "Automaton.h"
#include "Rules.h"
#include "ConcreteStates.h"

static void debugWord(const Word *w)
{
	switch(w->GetSymbol()){
		case SYM_v: std::cout<<"Keyword var"; break;
		case SYM_c: std::cout<<"Keyword const"; break;
		case SYM_r: std::cout<<"Function lire"; break;
		case SYM_w: std::cout<<"Function ecrire"; break;
		case SYM_op_par: std::cout<<"("; break;
		case SYM_cl_par: std::cout<<")"; break;
		case SYM_plus: std::cout<<"Operator +"; break;
		case SYM_minus: std::cout<<"Operator -"; break;
		case SYM_times: std::cout<<"Operator *"; break;
		case SYM_div: std::cout<<"Operator /"; break;
		case SYM_eq: std::cout<<"Operator ="; break;
		case SYM_aff: std::cout<<"Operator :="; break;
		case SYM_id: std::cout<<"Variable id "<<" ("<<*w->GetVal().varid<<")"; break;
		case SYM_n: std::cout<<"Number "<<" ("<<*w->GetVal().number<<")"; break;
		case SYM_pv: std::cout<<"Semicolon ";break;
		case SYM_vg: std::cout<<"Colon ";break;
		default:std::cout<<"Token code ("<<(int)(w->GetSymbol())<<")";
	}
	std::cout<<std::endl;
}

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
	std::string line;
	Word *w;
	bool error = false;

	while(stream && !error)
	{
		std::getline(stream, line);
		while(!line.empty() && !error)
		{
			w = analyzer.AnalyzeLine(line);
			debugWord(w);

			switch(states.top()->Transition(this, w))
			{
				case SR_TRANSITION: // Ok
					break;
				case SR_ACCEPT: // Should not happen
					break;
				default:
					std::cout << "Error within \""<< line << "\"" << std::endl;
					error = true;
					break;
			}
			delete w;
		}
	}

	if(!error) // EOF has been reached
	{
		UWordVal endVal = {0};
		Word *endWord = new Word(SYM_end, endVal);
		switch(states.top()->Transition(this, endWord))
		{
			case SR_TRANSITION: // Should not happen
				break;
			case SR_ACCEPT:
				std::cout << "That's a nice program you have there, buddy! ;) " << std::endl;
				break;
			case SR_ERROR:
				break;
			default:
				break;
		}
		delete endWord;
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


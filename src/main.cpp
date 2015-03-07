#include <iostream>
#include <sstream>
#include <string>

#include "Automaton.h"
#include "LexicalAnalyzer.h"

void LexerTest()
{
	std::string test  ="var x :=\n42\n;";
	Word* w;
	LexicalAnalyzer lexer;
	
	while(!test.empty())
	{
		w = lexer.AnalyzeLine(test);
		if(w != 0)
		{
			// for testing :
			switch(w->getSymbol()){
				case SYM_v: std::cout<<"Keyword var"; break;
				case SYM_aff: std::cout<<"Operator :="; break;
				case SYM_id: std::cout<<"Variable id "<<" ("<<*(std::string*)(w->getVal())<<")"; break;
				case SYM_n: std::cout<<"Number "<<" ("<<*(int*)w->getVal()<<")"; break;
				case SYM_pv: std::cout<<"Semicolon ";break;
				default:std::cout<<"Token code ("<<(int)(w->getSymbol())<<")";
			}
			std::cout<<std::endl;
			delete w;
		}
	}
}

int main(int argc, char** argv) {
	std::string code = 
		"var x;\n";
	std::istringstream iss(code);

	Automaton automaton;

	automaton.Read(iss);
	LexerTest();
	return 0;
}

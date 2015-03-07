#include <iostream>
#include <sstream>
#include <string>

#include "Automaton.h"
#include "LexicalAnalyzer.h"

void LexerTest()
{
	std::string test  ="var x   :=\n42\n;const constvar ecrire = (42+ 98/45*lire );";
	Word* w;
	LexicalAnalyzer lexer;
	
	while(!test.empty())
	{
		w = lexer.AnalyzeLine(test);
		if(w != 0)
		{
			// for testing :
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
				case SYM_id: std::cout<<"Variable id "<<" ("<<*(std::string*)(w->GetVal())<<")"; break;
				case SYM_n: std::cout<<"Number "<<" ("<<*(int*)w->GetVal()<<")"; break;
				case SYM_pv: std::cout<<"Semicolon ";break;
				case SYM_vg: std::cout<<"Colon ";break;
				default:std::cout<<"Token code ("<<(int)(w->GetSymbol())<<")";
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

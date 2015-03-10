#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Automaton.h"
//#include "LexicalAnalyzer.h"

struct Options
{
	bool a,o,p,e;
	Options():a(false),o(false),p(false),e(false){}

	void AddOption( const char* o )
	{
		std::string str(o);
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		
		if( str.compare("-a") )
		{
			this->a = true;
		} else if( str.compare("-e") )
		{
			this->e = true;
		} else if( str.compare("-p") )
		{
			this->p = true;
		} else if( str.compare("-o") )
		{
			this->o = true;
		}
	}
};

/* Test strings :
"var x   :=\n42\n;const constvar ecrire = (42+ 98/45*lire );"
*/

int main(int argc, char** argv)
{

	if( argc < 2 )
	{
		std::cerr << "Erreur - Un argument est attendu" << std::endl;
		return 1;
	}
	std::string file_path(argv[argc-1]);

	Options opt;

	for( int i = 1; i < argc-1; ++i)
	{
		opt.AddOption(argv[i]);
	}

	std::string code = 
		"var x ;\n\
		const n=42, n2=100 ;\n\
		ecrire n+n2; \n\
		x := n+n2 ;\n\
		ecrire x+2 ;\n\
		lire x; \n\
		ecrire x prout; \n";

	std::istringstream iss(code);

	Automaton automaton;
	automaton.Read(iss);
	if( opt.a )
		automaton.StaticAnalysis();
	if( opt.o )
		automaton.Transform();
	if( opt.p )
		automaton.Print();
	if( opt.e )
		automaton.Execute();

	automaton.TestAutomaton();

	std::cout << "fin" << std::endl;

	return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Automaton.h"
//#include "LexicalAnalyzer.h"

/* Test strings :
"var x   :=\n42\n;const constvar ecrire = (42+ 98/45*lire );"
*/

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

void PrintHelp()
{
	std::cout << std::endl <<
		"||-----------------------------------------------------"<< std::endl<<
		"||[AIDE] Appel du programme:"<< std::endl<<
		"||-----------------------------------------------------"<< std::endl<<
    	"||../lutin [-p] [-a] [-e] [-o] source.lt"<< std::endl<<
    	"||\t[-p] affiche le code source reconnu"<< std::endl<<
    	"||\t[-a] analyse le programme de maniere statique"<< std::endl<<
    	"||\t[-e] execute interactivement le programme"<< std::endl<<
    	"||\t[-o] optimise les expressions et instructions" << std::endl<<
		"||------------------------------------------------------"<< std::endl << std::endl;
}

int main(int argc, char** argv)
{

	if( argc < 2 )
	{
		std::cerr << "Erreur - Un argument est attendu" << std::endl;
		PrintHelp();
		return 1;
	}
	std::string file_path(argv[argc-1]);

	Options opt;

	for( int i = 1; i < argc-1; ++i)
	{
		opt.AddOption(argv[i]);
	}

	std::string code =
		"var x ;\n";
		
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

	return 0;
}

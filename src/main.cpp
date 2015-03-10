#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>

#include "Automaton.h"
#include "Program.h"

//#define USE_ARGS

#include "user.h"

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
	std::cerr << std::endl <<
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

void PrintError(const std::string& str)
{
	std::cerr << str << std::endl;
}

int main(int argc, char** argv)
{
	Options opt;
	Program program;
	Automaton automaton;
	Word *p;

#ifdef __STATIC_FILE__ // see user.h for custom build

	std::cerr << "using user.h" << std::endl;
	std::string file_path(STATIC_FILE_PATH);

#else

	// Check for arguments
	if( argc < 2 )
	{
		PrintError("Erreur - Un argument est attendu");
		PrintHelp();
		return 1;
	}


	std::string file_path(argv[argc-1]);

#endif

	std::ifstream file( file_path );

	if ( file )
    {
		std::stringstream buffer;

        buffer << file.rdbuf();

        file.close();

        // File ok, looking for options

        Options opt;

		for( int i = 1; i < argc-1; ++i)
		{
			opt.AddOption(argv[i]);
		}

		Automaton automaton;
		automaton.Read(buffer);
		if( opt.a )
			automaton.StaticAnalysis();
		if( opt.o )
			automaton.Transform();
		if( opt.p )
			automaton.Print();
		if( opt.e )
			automaton.Execute();

		automaton.TestAutomaton();

    } else {
    	PrintError("Erreur a l'ouverture du fichier "+ file_path);
    	return 1;
    }



	return 0;
}


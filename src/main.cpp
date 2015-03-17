#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>

#include "user.h"

#include "Automaton.h"
#include "Program.h"
#include "Options.h"
#include "Utils.h"

//#define USE_ARGS

namespace std {
#ifdef DEBUG
	Logger debug("debug",true);
#else
	
	Logger debug("debug",false);
#endif	
}

void PrintHelp(std::ostream &stream)
{
	stream << std::endl <<
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
	std::string filepath;
	std::ifstream file;

	Program program;
	Automaton automaton;
	Word *p;

#ifdef USE_ARGS
	// Check for arguments
	if( argc < 2 )
	{
		PrintError("Erreur - Un argument est attendu");
		PrintHelp(std::cerr);
		return 1;
	}
	else
	{
		for( int i = 1; i < argc-1; ++i)
		{
			opt.AddOption(argv[i]);
		}
		#ifdef __STATIC_FILE__ // see user.h for custom build

			std::debug << "using user.h" << endl;
			filepath = STATIC_FILE_PATH;

		#else
			filepath = argv[argc-1];

		#endif // __STATIC_FILE__
	}

	file.open(filepath.c_str());

	if ( file )
    {
		p = automaton.Read(file);
		program.Build(p);
		
		if( opt.a )
		{
			std::debug << "++++++++ Static Analysis +++++++" << std::endl;
			//program.TestProgram();
			program.StaticAnalysis();
		}
		if( opt.o )
		{
			std::debug << "++++++++ Transform +++++++" << std::endl;
			//automaton.Transform();
		}
		if( opt.p )
		{
			std::debug << "++++++++ Display Code +++++++" << std::endl;
			program.DisplayCode();
		}
		if( opt.e )
		{
			program.Execute();
		}

		//automaton.TestAutomaton();

        file.close();
    } else {
    	PrintError("Erreur a l'ouverture du fichier "+ filepath);
    	return 1;
    }

#else
	std::string code = "var x , y, jambon, optimizeThis; \n\
					    const salade=28, pate = 42 ;\n\
					    ecrire sample ;\n\
					    lire x;\n\n\
					    y := 1;\n\
					    x := 3;\n\
						jambon:=((2+y)*x)+4;\n\
						optimizeThis := 4*(5+8);\n\
						kitty := 4;\n\
						ecrire y;";
	std::istringstream iss(code);

	p = automaton.Read(iss);
	program.Build(p);

	std::debug << std::endl << "################" << std::endl;
	std::debug << "This is what Lutin understood:" << std::endl << std::endl;
	program.DisplayCode();


	program.Execute();

	std::debug << std::endl << "################" << std::endl;
	std::debug << "Static Analysis:" << std::endl << std::endl;

	program.StaticAnalysis();

#endif // USE_ARGS

	return 0;
}

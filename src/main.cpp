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
		"||[HELP] Program flags:"<< std::endl<<
		"||-----------------------------------------------------"<< std::endl<<
		"||../lutin [-p] [-a] [-e] [-o] source.lt"<< std::endl<<
		"||\t[-p] displays recognized source code"<< std::endl<<
		"||\t[-a] performs static analysis"<< std::endl<<
		"||\t[-e] executes the program"<< std::endl<<
		"||\t[-o] optimizes instructions and instructions" << std::endl<<
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

	// Check for arguments
	if( argc < 2 )
	{
		PrintError("ERROR: argument required");
		PrintHelp(std::cerr);
		return 1;
	}
	else
	{
		for( int i = 1; i < argc-1; ++i)
		{
			opt.AddOption(argv[i]);
		}

		filepath = argv[argc-1];
	}

	file.open(filepath.c_str());

	if ( file )
	{
		p = automaton.Read(file);
		if(p != 0) // p is a valid program
		{
			program.Build(p);
			
			if( opt.a )
			{
				program.StaticAnalysis();
			}
			if( opt.o )
			{
				program.Optimize();
			}
			if( opt.p )
			{
				program.DisplayCode();
			}
			if( opt.e )
			{
				program.Execute();
			}

			delete p;
		}
		else
		{
			std::cerr << "ERROR: Fix the code and try again later ;)" << std::endl;
		}

		file.close();
	}
	else
	{
		PrintError("ERROR: cannot open file "+ filepath);
		return 1;
	}

	return 0;
}

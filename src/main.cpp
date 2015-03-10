#include <iostream>
#include <sstream>
#include <string>

#include "Automaton.h"
#include "LexicalAnalyzer.h"
#include "Program.h"

/* Test strings :
"var x   :=\n42\n;const constvar ecrire = (42+ 98/45*lire );"
*/

int main(int argc, char** argv) {
	std::cout << argc << std::endl;

	std::string code = 
		"var x ;\n";
	std::istringstream iss(code);

	Automaton automaton;
	Program program;

	//automaton.TestAutomaton();

	Word *p = automaton.Read(iss);

	if(p)
	{
		program.Build(p);
	}

	return 0;
}


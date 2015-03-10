#include <iostream>
#include <sstream>
#include <string>

#include "Automaton.h"
#include "LexicalAnalyzer.h"

/* Test strings :
"var x   :=\n42\n;const constvar ecrire = (42+ 98/45*lire );"
*/

int main(int argc, char** argv) {
	std::string code = 
		"var x ;\nx := 42 ;\n";
	std::istringstream iss(code);

	Automaton automaton;

	automaton.Read(iss);
	return 0;
}


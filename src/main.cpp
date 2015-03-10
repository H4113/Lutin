#include <iostream>
#include <sstream>
#include <string>

#include "Automaton.h"
#include "LexicalAnalyzer.h"

/* Test strings :
"var x   :=\n42\n;const constvar ecrire = (42+ 98/45*lire );"
*/

int main(int argc, char** argv) {
	std::cout << argc << std::endl;

	std::string code = 
		"var x ;\n\
		const n=42, n2=100 ;\n\
		ecrire n+n2; \n\
		x := n+n2 ;\n\
		ecrire x+2 ;\n\
		lire x; \n\
		ecrire x; \n";
	std::istringstream iss(code);

	Automaton automaton;
	automaton.TestAutomaton();

	//automaton.Read(iss);
	return 0;
}

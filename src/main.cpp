#include <iostream>
#include <sstream>
#include <string>

#include "Automaton.h"

int main(int argc, char** argv) {
	std::string code = 
		"var x;\n";
	std::istringstream iss(code);

	Automaton automaton;

	automaton.Read(iss);

	return 0;
}

/**
 * Project Lutin
 */


#include "Read.h"
#include <iostream>

/**
 * Read implementation
 */

Read::Read(Variable* v) : var(v) {
	
}

void Read::display() const {
	std::cout << toString() << ";" << std::endl;
}

int Read::execute() {
	int val;
	std::cin >> val;
	var->set(val);
	return val;
}

std::string Read::toString() const {
	return "lire " + var->getName();
}

/**
 * Project Lutin
 */


#include "Read.h"
#include <iostream>

/**
 * Read implementation
 */

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
	return "ecrire " + var->getName();
}

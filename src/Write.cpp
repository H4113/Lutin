/**
 * Project Lutin
 */


#include "Write.h"
#include <iostream>

/**
 * Write implementation
 */

void Write::display() const {
	std::cout << toString() << ";" << std::endl;
}

int Write::execute() {
	return 0;
}

std::string Write::toString() const {
	return "ecrire " + expression->toString();
}

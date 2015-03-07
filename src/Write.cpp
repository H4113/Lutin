/**
 * Project Lutin
 */


#include "Write.h"
#include <iostream>

/**
 * Write implementation
 */

Write::Write(Expression* e) : expression(e) {
	
}

void Write::display() const {
	std::cout << toString() << ";" << std::endl;
}

int Write::execute() {
	int v = expression->execute();
	std::cout << std::to_string(v) << std::endl;
	return v;
}

std::string Write::toString() const {
	return "ecrire " + expression->toString();
}

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

}

std::string Write::toString() const {
	return "write " + expression->toString();
}

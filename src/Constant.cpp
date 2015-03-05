/**
 * Project Lutin
 */


#include "Constant.h"
#include <iostream>

/**
 * Constant implementation
 */


/**
 * @param value
 */
Constant::Constant(const int& value) {
	*pointer = value;
}

void Constant::display() const {
	std::cout << toString() << ";" << std::endl;
}

std::string Constant::toString() const {
	return "const " + name + " = " + std::to_string(*pointer);
}

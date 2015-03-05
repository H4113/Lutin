/**
 * Project Lutin
 */


#include "Value.h"
#include <iostream>

/**
 * Value implementation
 */

void Value::display() const {
 	std::cout << toString() << ";" << std::endl;
}

std::string Value::toString() const {
	return std::to_string(*pointer);
}

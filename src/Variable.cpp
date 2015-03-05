/**
 * Project Lutin
 */


#include "Variable.h"
#include <iostream>

/**
 * Variable implementation
 */


Variable::Variable() {

}

std::string Variable::getName() const {
	return name;
}

void Variable::display() const {
	std::cout << toString() << ";" << std::endl;
}

bool Variable::getInitialized() const {
	return initialized;
}

std::string Variable::toString() const {
	return "var " + name;
}

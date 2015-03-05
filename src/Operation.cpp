/**
 * Project Lutin
 */


#include "Operation.h"

/**
 * Operation implementation
 */

void Operation::display() const {
	std::cout << toString() << ";" << std::endl;
}

std::string Operation::toString() const {
	std::string oper;
	switch(op) {
		case PLUS:
			oper = "+";
			break;
		case MINUS:
			oper = "-";
			break;
		case DIVIDED:
			oper = "/";
			break;
		case TIMES:
			oper = "*";
			break;
		default: // dead code
			oper = "+";
			break;
	}
	return exp1->toString() + oper + exp2->toString();
}

int Operation::execute() {
	switch(op) {
		case PLUS:
			return exp1->execute() + exp2->execute();
			break;
		case MINUS:
			return exp1->execute() - exp2->execute();
			break;
		case DIVIDED:
			return exp1->execute() / exp2->execute();
			break;
		case TIMES:
			return exp1->execute() * exp2->execute();
			break;
		default: // dead code
			return exp1->execute() + exp2->execute();
			break;
	}
}

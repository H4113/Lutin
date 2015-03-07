/**
 * Project Lutin
 */

#include "Assignment.h"

/**
 * Assignment implementation
 */

Assignment::Assignment(Variable* v, Expression* e) : var(v), exp(e) 
{

}

std::string Assignment::toString(void) const 
{
	return var->toString() + " := " + exp->toString();
}

void Assignment::display(void) const 
{
	std::cout << toString() << std::endl;
}

int Assignment::execute(void) 
{
	return exp->execute();
}

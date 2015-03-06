/**
 * Project Lutin
 */


#include "Word.h"

/**
 * Word implementation
 */

Word::Word(Symbol nsymbol, void* nval) :
	symbol(nsymbol), val(nval)
{
}

Word::~Word()
{
	// Cannot delete val if it's not cast into non void pointer
	//delete val;
}

Symbol Word::getSymbol() const {
	return symbol;
}

void* Word::getVal() const {
	return val;
}

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
	delete val;
}

Symbol Word::getSymbol() const {
	return symbol;
}

void* Word::getVal() const {
	return val;
}

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

void Word::SetSymbol(Symbol nsymbol) 
{
	symbol = nsymbol;
}

Symbol Word::GetSymbol(void) const 
{
	return symbol;
}

void* Word::GetVal(void) const 
{
	return val;
}


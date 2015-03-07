/**
 * Project Lutin
 */

#include "Word.h"
#include "Symbol.h"

/**
 * Word implementation
 */

Word::Word(Symbol nsymbol, UWordVal nval) :
	symbol(nsymbol), val(nval)
{
}

Word::~Word()
{
	if(symbol == SYM_id) {
		delete val.varid;
	} else if(symbol == SYM_n) {
		delete val.number;
	}
}

void Word::SetSymbol(Symbol nsymbol) 
{
	symbol = nsymbol;
}

Symbol Word::GetSymbol(void) const 
{
	return symbol;
}

UWordVal Word::GetVal(void) const 
{
	return val;
}


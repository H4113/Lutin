/**
 * Project Lutin
 */

#ifndef _WORD_H
#define _WORD_H

#include <string>

#include "Symbol.h"

union UWordVal
{
	std::string* varid;
	int* number;
};

class Word 
{
	public:
		Word();
		Word(Symbol nsymbol, UWordVal nval);
		virtual ~Word();
	
		void SetSymbol(Symbol symbol);

		Symbol GetSymbol(void) const;
		UWordVal GetVal(void) const;

	private: 
		Symbol symbol;

		UWordVal val;
};

#endif //_WORD_H

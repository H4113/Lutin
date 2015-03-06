/**
 * Project Lutin
 */


#ifndef _WORD_H
#define _WORD_H

#include "Symbol.h"


class Word {
	public:
		Word();
		Word(Symbol nsymbol, void* nval);
		virtual ~Word();
		
		Symbol getSymbol() const;
		void* getVal() const;

	private: 
		Symbol symbol;
		void* val;
};

#endif //_WORD_H

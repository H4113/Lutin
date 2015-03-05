/**
 * Project Lutin
 */


#ifndef _WORD_H
#define _WORD_H

#include "Symbol.h"


class Word {
	public:
		Word(Symbol nsymbol, void* nval);
		virtual ~Word();
	private: 
		Symbol symbol;
		void* val;

	public:
		Symbol getSymbol() const;
		void* getVal() const;
		Word();
};

#endif //_WORD_H

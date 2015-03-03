/**
 * Project Lutin
 */


#ifndef _WORD_H
#define _WORD_H

#include "Symbol.h"


class Word {
	private: 
		Symbol symbol;
		void* val;

	public:
		Symbol getSymbol() const;
		void* getVal() const;
		Word();
};

#endif //_WORD_H

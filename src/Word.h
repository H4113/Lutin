/**
 * Project Lutin
 */

#ifndef _WORD_H
#define _WORD_H

#include <string>

#include "Symbol.h"

class Word;

/**
 *  @brief A list of words
 */
struct WordContainer
{
	Word **words;
	unsigned int size;
};

/**
 *  @brief Union containing a Word's value.
 * a string for the id of a variable, an int for the number, ... .
 */
union UWordVal
{
	std::string* varid;
	int* number;
	WordContainer *wordContainer;
};

/**
 *	@class Word
 *  @brief A token generated by the LexicalAnalyser
 */
class Word 
{
	public:
		Word();
		Word(Symbol nsymbol, UWordVal nval);
		virtual ~Word();
	
		void SetSymbol(Symbol symbol);

		Symbol GetSymbol(void) const;
		UWordVal GetVal(void) const;

		static void DebugWord(const Word *w);

	private: 
		Symbol symbol;
		UWordVal val;
};

#endif //_WORD_H

/**
 * Project Lutin
 */


#ifndef _LEXICALANALYZER_H
#define _LEXICALANALYZER_H


#include <string>
#include "Program.h"
#include "Word.h"

class LexicalAnalyzer 
{
	public:
		/** Constructor */
		LexicalAnalyzer();
		/** Get the current word of str 
		* if the current word is not known str will be modified
		* else it only return the last current word, use shift
		* afterward to get the next */
		Word* GetCurrentWord(std::string & str);
		/** Set the position of the Lexer on the next word */
		void Shift();
		/** read (and return) the current word and then shift 
		* str will be modified */
		Word* ReadNextWord(std::string & str);
		
	protected:
		
	private: 
		bool lastWordKnown;
		Word* currentWord;
};

#endif //_LEXICALANALYZER_H

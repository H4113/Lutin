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

		/** Set the stream to analyze */
		void SetInputStream(std::istream *nstream);

		/** Get the current word of str 
		* if the current word is not known str will be modified
		* else it only return the last current word, use shift
		* afterward to get the next */
		Word* GetCurrentWord();

		/** Set the position of the Lexer on the next word */
		void Shift();

		/** read (and return) the current word and then shift 
		* str will be modified */
		Word* ReadNextWord();

		/** Check if it's the end of the stream */
		bool Eof() const;

		unsigned int GetCurrentLine();
		unsigned int GetCurrentCharacter();

	protected:
		
	private: 
		bool lastWordKnown;
		Word* currentWord;
		std::istream* stream;
		std::string str;
		unsigned int lineCount;			// for debug
		unsigned int oldCharacterCount;
		unsigned int characterCount;	// for debug
};

#endif //_LEXICALANALYZER_H

/**
 * Project Lutin
 */


#ifndef _LEXICALANALYZER_H
#define _LEXICALANALYZER_H


#include <string>
#include "Program.h"
#include "Word.h"

/**
 *	@class LexicalAnalyzer 
 * Transforms a string stream in a tokens represented by 
 * the Word class
 */
class LexicalAnalyzer 
{
	public:
		/** Constructor */
		LexicalAnalyzer();
		
		/** Destructor */
		virtual ~LexicalAnalyzer();

		/** Set the stream to analyze
		* @param nstream input stream */
		void SetInputStream(std::istream *nstream);

		/** Get the current word of str 
		* if the current word is not known str will be modified
		* else it only return the last current word, use shift
		* afterward to get the next 
		* @return the word read */
		Word* GetCurrentWord();

		/** Set the position of the Lexer on the next word */
		void Shift();

		/** read (and return) the current word and then shift 
		* str will be modified */
		Word* ReadNextWord();

		/** Check if it's the end of the stream */
		bool Eof() const;

		/** Get the current line read by the lexer */
		unsigned int GetCurrentLine();

		/** Get the current position of the next character
		* read by the lexer **/
		unsigned int GetCurrentCharacter();
		
		/** Return true if a lexer error occured */
		bool HasError(void) const;

	private: 
		bool lastWordKnown;
		bool error;
		Word* currentWord;
		std::istream* stream;
		std::string str;
		unsigned int lineCount;
		unsigned int oldCharacterCount;
		unsigned int characterCount;
};

#endif //_LEXICALANALYZER_H

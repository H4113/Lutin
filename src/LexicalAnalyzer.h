/**
 * Project Lutin
 */


#ifndef _LEXICALANALYZER_H
#define _LEXICALANALYZER_H


#include <string>
#include <regex>
#include "Program.h"
#include "Word.h"

struct LexResult
{
	int error;
	char* value;
	Symbol symbol;
};

class LexicalAnalyzer {
	public:
		static Word* AnalyzeLine(std::string & str);
	protected:
		
	private: 
		Program analyzer;

		static const int NB_RULES;
		static const std::regex reg[];
		static const Symbol symbols[];
		static const std::regex regJunk;
};

#endif //_LEXICALANALYZER_H

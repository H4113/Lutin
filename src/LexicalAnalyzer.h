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
		LexicalAnalyzer();
		Word* AnalyzeLine(std::string & str);
		
	protected:
		
	private: 

		Program analyzer;
};

#endif //_LEXICALANALYZER_H

/**
 * Project Lutin
 */


#include "LexicalAnalyzer.h"
#include <iostream>

const int LexicalAnalyzer::NB_RULES = 5;
const std::regex LexicalAnalyzer::reg[LexicalAnalyzer::NB_RULES] = {
	std::regex("^var +"),
	std::regex("^:= +"),
	std::regex("^([a-zA-Z][a-zA-Z0-9]*)\\s+"),
	std::regex("^([0-9]+)[^0-9]+"),
	std::regex("^;")
};
const Symbol LexicalAnalyzer::symbols[LexicalAnalyzer::NB_RULES] = {
	SYM_v,
	SYM_aff,
	SYM_id,
	SYM_n,
	SYM_pv
};
const std::regex LexicalAnalyzer::regJunk("^[ \\t\\n]+");

/**
 * LexicalAnalyzer implementation
 */
Word* LexicalAnalyzer::AnalyzeLine(std::string & str)
{
	if(str.empty())
	{
		
		return 0;
	}
	std::smatch match;
	if(std::regex_search(str, match, regJunk) ) {
		std::cout << "junk"<<std::endl;
		str.erase(str.begin(),str.begin()+match[0].length());
		return 0;
	}
	for(int i=0; i<LexicalAnalyzer::NB_RULES;++i) {
		if(std::regex_search(str, match, reg[i]) ) {
			Symbol symbolReturn = symbols[i];
			void* valReturn = 0;
			if(match.size() >= 2) {
				if(symbolReturn == SYM_id) {
					valReturn = new std::string(match[1].str());
				}
				if(symbolReturn == SYM_n) {
					valReturn = 0; // todo convert to int
				}
				str.erase(str.begin(),str.begin()+match[1].length());
			}else{
				str.erase(str.begin(),str.begin()+match[0].length());
			}
			Word* wordReturn = new Word(symbolReturn, valReturn);
			return wordReturn;
		}
	}
	std::cout << "lexer error"<<std::endl;
	str.erase(str.begin(),str.begin()+1);
	return 0;
}

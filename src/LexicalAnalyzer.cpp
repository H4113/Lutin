/**
 * Project Lutin
 */


#include "LexicalAnalyzer.h"
#include "Utils.h"
#include <iostream>
#include <regex>

const int NB_RULES = 5;
const std::regex reg[NB_RULES] = {
	std::regex("^var +"),
	std::regex("^:= +"),
	std::regex("^([a-zA-Z][a-zA-Z0-9]*)\\s+"),
	std::regex("^([0-9]+)[^0-9]+"),
	std::regex("^;")
};
const Symbol symbols[NB_RULES] = {
	SYM_v,
	SYM_aff,
	SYM_id,
	SYM_n,
	SYM_pv
};
const std::regex regJunk("^[ \\t\\n]+");

/**
 * LexicalAnalyzer implementation
 */

LexicalAnalyzer::LexicalAnalyzer()
{
}

Word* LexicalAnalyzer::AnalyzeLine(std::string & str)
{
	if(str.empty()) {
		return 0;
	}
	std::smatch match;
	// erase blank characters at the begining of the string
	if(std::regex_search(str, match, regJunk) ) {
		str.erase(str.begin(),str.begin()+match[0].length());
	}
	if(str.empty()) {
		return 0;
	}
	// test all the rules
	for(int i=0; i<NB_RULES;++i) {
		if(std::regex_search(str, match, reg[i]) ) {
			Symbol symbolReturn = symbols[i];

			void* valReturn = 0; // to save the matched value
			if(match.size() >= 2) { 
				if(symbolReturn == SYM_id) {
					valReturn = new std::string(match[1].str());
				}else if(symbolReturn == SYM_n) {
					valReturn = new int(stot<int>(match[1].str()));
				}
				str.erase(str.begin(),str.begin()+match[1].length());
			}else{
				str.erase(str.begin(),str.begin()+match[0].length());
			}

			Word* wordReturn = new Word(symbolReturn, valReturn);
			return wordReturn;
		}
	}
	// no matched rules:
	std::cout << "lexer error"<<std::endl;
	str.erase(str.begin(),str.begin()+1);
	return 0;
}


/**
 * Project Lutin
 */


#include "LexicalAnalyzer.h"
#include "Utils.h"
#include <iostream>
#include <regex>

 /**
 * LexicalAnalyzer implementation
 */

const int NB_RULES = 16;
const std::regex REG[NB_RULES] = {
	std::regex("^var\\s"),
	std::regex("^ecrire\\s"),
	std::regex("^lire\\s"),
	std::regex("^const\\s"),
	std::regex("^:="),
	std::regex("^;"),
	std::regex("^,"),
	std::regex("^\\+"),
	std::regex("^\\-"),
	std::regex("^\\*"),
	std::regex("^/"),
	std::regex("^="),
	std::regex("^\\("),
	std::regex("^\\)"),
	std::regex("^([a-zA-Z][a-zA-Z0-9]*)[^a-zA-Z0-9]"),
	std::regex("^([0-9]+)[^0-9]+")
};
const Symbol SYMBOLS[NB_RULES] = {
	SYM_v,
	SYM_w,
	SYM_r,
	SYM_c,
	SYM_aff,
	SYM_pv,
	SYM_vg,
	SYM_plus,
	SYM_minus,
	SYM_times,
	SYM_div,
	SYM_eq,
	SYM_op_par,
	SYM_cl_par,
	SYM_id,
	SYM_n
};
const std::regex REG_JUNK("^\\s+");

LexicalAnalyzer::LexicalAnalyzer() :
	lastWordKnown(false)
{
}

Word* LexicalAnalyzer::GetCurrentWord(std::string & str)
{
	if(lastWordKnown) {
		return currentWord;
	}
	std::smatch match;
	if(str.empty()) {
		return 0;
	}
	// erase blank characters at the begining of the string
	if(std::regex_search(str, match, REG_JUNK) ) {
		str.erase(str.begin(),str.begin()+match[0].length());
	}
	if(str.empty()) {
		return 0;
	}
	// test all the rules
	for(int i=0; i<NB_RULES;++i) {
		if(std::regex_search(str, match, REG[i]) ) {
			Symbol symbolReturn = SYMBOLS[i];

			UWordVal valReturn; // to save the matched value
			if(match.size() >= 2) { 
				if(symbolReturn == SYM_id) {
					valReturn.varid = new std::string(match[1].str());
				}else if(symbolReturn == SYM_n) {
					valReturn.number = new int(stot<int>(match[1].str()));
				}
				str.erase(str.begin(),str.begin()+match[1].length());
			} else {
				str.erase(str.begin(),str.begin()+match[0].length());
			}

			lastWordKnown = true;
			currentWord = new Word(symbolReturn, valReturn);
			return currentWord;
		}
	}
	// no matched rules:
	std::cout << "lexer error"<<std::endl;
	str.erase(str.begin(),str.begin()+1);
	return 0;
}

void LexicalAnalyzer::Shift()
{
	lastWordKnown = false;
}

Word* LexicalAnalyzer::ReadNextWord(std::string & str)
{
	GetCurrentWord(str);
	Shift();
	return currentWord;	
}
/**
 * Project Lutin
 */


#include "LexicalAnalyzer.h"
#include "Utils.h"
#include <iostream>

#ifndef USE_BOOST
#include <regex>
using namespace std;
#else
#include <boost/regex.hpp>
using namespace boost;
#endif
 /**
 * LexicalAnalyzer implementation
 */

const int NB_RULES = 16;
const regex REG[NB_RULES] = {
	regex("^var\\s"),
	regex("^ecrire\\s"),
	regex("^lire\\s"),
	regex("^const\\s"),
	regex("^:="),
	regex("^;"),
	regex("^,"),
	regex("^\\+"),
	regex("^\\-"),
	regex("^\\*"),
	regex("^/"),
	regex("^="),
	regex("^\\("),
	regex("^\\)"),
	regex("^([a-zA-Z][a-zA-Z0-9]*)[^a-zA-Z0-9]"),
	regex("^([0-9]+)[^0-9]+")
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
const regex REG_JUNK("^\\s+");

LexicalAnalyzer::LexicalAnalyzer() :
	lastWordKnown(false), currentWord(0), stream(), str()
{
}

void LexicalAnalyzer::SetInputStream(std::istream *nstream)
{
	stream = nstream;
	lineCount = 0;
	characterCount = 0;
}

Word* LexicalAnalyzer::GetCurrentWord()
{
	if(lastWordKnown) {
		return currentWord;
	}
	// get the new line 
	if(str.empty()) {
		++lineCount;
		characterCount = 0;
		std::getline(*stream, str);
	}
	// EOF case
	if(stream->eof()){
		UWordVal endVal = {0};
		currentWord = new Word(SYM_end, endVal);
		return currentWord;
	}

	smatch match;
	// erase blank characters at the begining of the string
	if(regex_search(str, match, REG_JUNK) ) {
		characterCount += match[0].length();
		str.erase(str.begin(),str.begin()+match[0].length());
	}
	if(str.empty()) {
		return 0;
	}
	// test all the rules
	for(int i=0; i<NB_RULES;++i) {
		if(regex_search(str, match, REG[i]) ) {
			Symbol symbolReturn = SYMBOLS[i];

			UWordVal valReturn; // to save the matched value
			unsigned int nbCharactersToErase;
			if(match.size() >= 2) { 
				if(symbolReturn == SYM_id) {
					valReturn.varid = new std::string(match[1].str());
				}else if(symbolReturn == SYM_n) {
					valReturn.number = new int(stot<int>(match[1].str()));
				}
				nbCharactersToErase = match[1].length();
			} else {
				nbCharactersToErase = match[0].length();
			}
			str.erase(str.begin(),str.begin()+nbCharactersToErase);
			characterCount += nbCharactersToErase;

			lastWordKnown = true;
			currentWord = new Word(symbolReturn, valReturn);
			return currentWord;
		}
	}
	// no matched rules:
	std::cerr << "Lexer error ("<< lineCount <<":"<< characterCount
			  << ") : character "<<str[0]<<" unkown."<<std::endl;
	characterCount += 1;
	str.erase(str.begin(),str.begin()+1);
	currentWord = 0;
	return currentWord;
}

void LexicalAnalyzer::Shift()
{
	lastWordKnown = false;
}

Word* LexicalAnalyzer::ReadNextWord()
{
	GetCurrentWord();
	Shift();
	return currentWord;	
}

bool LexicalAnalyzer::Eof() const 
{
	return !stream || stream->eof();
}

unsigned int LexicalAnalyzer::GetCurrentLine()
{
	return lineCount;
}

unsigned int LexicalAnalyzer::GetCurrentCharacter()
{
	return characterCount;
}

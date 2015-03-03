/**
 * Project Lutin
 */


#include "Word.h"

/**
 * Word implementation
 */

Word::Word(){
}

Symbol Word::getSymbol() const {
	return symbol;
}

void* Word::getVal() const {
	return val;
}

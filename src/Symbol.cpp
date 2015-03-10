#include "Symbol.h"

bool IsTerminal(Symbol s){
	return s<SYM_Pprim;
}

/**
 * Project Lutin
 */

 #include <iostream>

#include "Word.h"
#include "Symbol.h"
#include "Utils.h"

/**
 * Word implementation
 */

Word::Word(Symbol nsymbol, UWordVal nval) :
	symbol(nsymbol), val(nval)
{
}

Word::~Word()
{
	if(symbol == SYM_id) {
		delete val.varid;
	} else if(symbol == SYM_n) {
		delete val.number;
	}
}

void Word::SetSymbol(Symbol nsymbol) 
{
	symbol = nsymbol;
}

Symbol Word::GetSymbol(void) const 
{
	return symbol;
}

UWordVal Word::GetVal(void) const 
{
	return val;
}

void Word::DebugWord(const Word *w)
{
	switch(w->GetSymbol()){
		case SYM_v: std::debug<<"Keyword var"; break;
		case SYM_c: std::debug<<"Keyword const"; break;
		case SYM_r: std::debug<<"Function lire"; break;
		case SYM_w: std::debug<<"Function ecrire"; break;
		case SYM_op_par: std::debug<<"("; break;
		case SYM_cl_par: std::debug<<")"; break;
		case SYM_plus: std::debug<<"Operator +"; break;
		case SYM_minus: std::debug<<"Operator -"; break;
		case SYM_times: std::debug<<"Operator *"; break;
		case SYM_div: std::debug<<"Operator /"; break;
		case SYM_eq: std::debug<<"Operator ="; break;
		case SYM_aff: std::debug<<"Operator :="; break;
		case SYM_id: std::debug<<"Variable id "<<" ("<<*w->GetVal().varid<<")"; break;
		case SYM_n: std::debug<<"Number "<<" ("<<*w->GetVal().number<<")"; break;
		case SYM_pv: std::debug<<"Semicolon ";break;
		case SYM_vg: std::debug<<"Colon ";break;
		case SYM_end: std::debug<<"EOF";break;
		case SYM_Pprim: std::debug<<"P'";break;
		case SYM_P: std::debug<<"P (Program)";break;
		case SYM_Pd: std::debug<<"Pd (Program declaration)";break;
		case SYM_Pi: std::debug<<"Pi (Program instructions)";break;
		case SYM_D: std::debug<<"D (Declaration)";break;
		case SYM_Lval: std::debug<<"Lval";break;
		case SYM_Lconst: std::debug<<"Lconst";break;
		case SYM_I: std::debug<<"I (Instruction)";break;
		case SYM_E: std::debug<<"E (Expression)";break;
		default:std::debug<<"Token code ("<<(int)(w->GetSymbol())<<")";
	}
	std::debug<<std::endl;
}

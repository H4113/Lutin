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
	if(symbol == SYM_id)
	{
		delete val.varid;
	}
	else if(symbol == SYM_n)
	{
		delete val.number;
	}
	else if(!IsTerminal(symbol)) // Has a container
	{
		for(unsigned int i = 0; i < val.wordContainer->size; ++i)
		{
			delete val.wordContainer->words[i];
		}
		delete [] val.wordContainer->words;
		delete val.wordContainer;
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
	switch(w->GetSymbol())
	{
		case SYM_v: std::cout<<"Keyword var"; break;
		case SYM_c: std::cout<<"Keyword const"; break;
		case SYM_r: std::cout<<"Function lire"; break;
		case SYM_w: std::cout<<"Function ecrire"; break;
		case SYM_op_par: std::cout<<"("; break;
		case SYM_cl_par: std::cout<<")"; break;
		case SYM_plus: std::cout<<"Operator +"; break;
		case SYM_minus: std::cout<<"Operator -"; break;
		case SYM_times: std::cout<<"Operator *"; break;
		case SYM_div: std::cout<<"Operator /"; break;
		case SYM_eq: std::cout<<"Operator ="; break;
		case SYM_aff: std::cout<<"Operator :="; break;
		case SYM_id: std::cout<<"Variable id "<<" ("<<*w->GetVal().varid<<")"; break;
		case SYM_n: std::cout<<"Number "<<" ("<<*w->GetVal().number<<")"; break;
		case SYM_pv: std::cout<<"Semicolon ";break;
		case SYM_vg: std::cout<<"Colon ";break;
		case SYM_end: std::cout<<"EOF";break;
		case SYM_Pprim: std::cout<<"P'";break;
		case SYM_P: std::cout<<"P (Program)";break;
		case SYM_Pd: std::cout<<"Pd (Program declaration)";break;
		case SYM_Pi: std::cout<<"Pi (Program instructions)";break;
		case SYM_D: std::cout<<"D (Declaration)";break;
		case SYM_Lval: std::cout<<"Lval";break;
		case SYM_Lconst: std::cout<<"Lconst";break;
		case SYM_I: std::cout<<"I (Instruction)";break;
		case SYM_E: std::cout<<"E (Expression)";break;
		default: std::cout<<"Token code ("<<(int)(w->GetSymbol())<<")";
	}
	std::cout<<std::endl;
}

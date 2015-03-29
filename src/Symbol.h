/**
 * Project Lutin
 */


#ifndef _SYMBOL_H
#define _SYMBOL_H

#include <string>

enum Symbol 
{
	SYM_pv,		// ;
	SYM_v,		// var
	SYM_c,		// const
	SYM_id,		// (variable id)
	SYM_vg,		// ,
	SYM_eq,		// =
	SYM_n,		// (number)
	SYM_w,		// ecrire
	SYM_r,		// lire
	SYM_aff,	// :=
	SYM_plus,	// +
	SYM_times,	// *
	SYM_minus,	// -
	SYM_div,	// /
	SYM_op_par,	// (
	SYM_cl_par,	// )
	SYM_end,	// $

	SYM_Pprim,	// P'
	SYM_P,		// P
	SYM_Pd,		// Pd
	SYM_Pi,		// Pi
	SYM_D,		// D
	SYM_Lval,	// Lval
	SYM_Lconst,	// Lconst
	SYM_I,		// I
	SYM_E 		// E
};

/*
*	Returns true if symbol is terminal. False if not.
*/
bool IsTerminal(Symbol s);

std::string SymbolToString(Symbol s);

#endif //_SYMBOL_H

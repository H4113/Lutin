/**
 * Project Lutin
 */


#ifndef _SYMBOL_H
#define _SYMBOL_H

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
	SYM_end,	// 

	SYM_Pprim,
	SYM_P,
	SYM_Pd,
	SYM_Pi,
	SYM_D,
	SYM_Lval,
	SYM_Lconst,
	SYM_I,
	SYM_E
};

#endif //_SYMBOL_H

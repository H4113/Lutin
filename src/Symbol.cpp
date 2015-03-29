#include <sstream>

#include "Symbol.h"

bool IsTerminal(Symbol s)
{
	return s<SYM_Pprim;
}

std::string SymbolToString(Symbol s)
{
	std::ostringstream oss;

	switch(s)
	{
		case SYM_pv:
			oss << "symbol ;";
			break;
		case SYM_v:
			oss << "keyword var";
			break;
		case SYM_c:
			oss << "keyword const";
			break;
		case SYM_id:
			oss << "identifier";
			break;
		case SYM_vg:
			oss << "symbol ,";
			break;
		case SYM_eq:
			oss << "symbol =";
			break;
		case SYM_n:
			oss << "number";
			break;
		case SYM_w:
			oss << "keyword ecrire";
			break;
		case SYM_r:
			oss << "keyword lire";
			break;
		case SYM_aff:
			oss << "operator :=";
			break;
		case SYM_plus:
			oss << "arithmetic operator +";
			break;
		case SYM_times:
			oss << "arithmetic operator *";
			break;
		case SYM_minus:
			oss << "arithmetic operator -";
			break;
		case SYM_div:
			oss << "arithmetic operator /";
			break;
		case SYM_op_par:
			oss << "symbol (";
			break;
		case SYM_cl_par:
			oss << "symbol )";
			break;
		case SYM_end:
			oss << "end of stream";
			break;
		default:
			oss << "symbol with id " << (int)(s);
			break;
	}
	return oss.str();
}


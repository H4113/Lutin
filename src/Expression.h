/**
 * Project Lutin
 */


#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Instruction.h"


class Expression : public Instruction
{
	protected:
		Expression(bool p = false);
		bool parenthesis;
};

#endif //_EXPRESSION_H

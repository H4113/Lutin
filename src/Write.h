/**
 * Project Lutin
 */


#ifndef _WRITE_H
#define _WRITE_H

#include "Instruction.h"
#include "Expression.h"


class Write: public Instruction {
	private: 
		Expression expression;
};

#endif //_WRITE_H
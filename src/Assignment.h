/**
 * Project Lutin
 */


#ifndef _ASSIGNMENT_H
#define _ASSIGNMENT_H

#include "Instruction.h"
#include "Variable.h"
#include "Expression.h"


class Assignment: public Instruction {
	private: 
		Variable var;
		Expression exp;
};

#endif //_ASSIGNMENT_H

/**
 * Project Lutin
 */


#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "Instruction.h"
#include "Variable.h"


class Program {
private: 
	Vector<Instruction> instructions;
	Vector<Variable> variables;
};

#endif //_PROGRAM_H
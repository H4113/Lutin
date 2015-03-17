/**
 * Project Lutin
 */


#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <string>
#include <set>

class Variable;

enum InstruType
{
	IT_OPE,
	IT_ASS,
	IT_VAR,
	IT_CON,
	IT_VAL,
	IT_NES, // NESTED
	IT_REA,
	IT_WRI
};

class Instruction 
{
	public: 
		Instruction();
		virtual int Execute(void) = 0;
		
		virtual void Display(void) const = 0;

		virtual std::string ToString(void) const = 0;

		virtual void GetVariables(std::set<const Variable*> &set) const = 0;

		virtual InstruType GetInstructionType() const = 0;
};

#endif //_INSTRUCTION_H

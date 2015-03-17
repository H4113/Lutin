/**
 * Project Lutin
 */


#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <string>
#include <set>

class Variable;

class Instruction 
{
	public: 
		Instruction();
		virtual int Execute(void) = 0;
		
		virtual void Display(void) const = 0;

		virtual std::string ToString(void) const = 0;

		virtual void GetVariables(std::set<const Variable*> &set) const = 0;

		virtual Variable* GetModifiedVariable(void) const;
};

#endif //_INSTRUCTION_H

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
		virtual ~Instruction();

		virtual int Execute(void) = 0;
		
		virtual void Display(void) const = 0;

		virtual std::string ToString(void) const = 0;

		virtual InstruType GetInstructionType() const = 0;

		/*
		* Add all the variables in the instruction to the set passed in parameters 
		* @param set<Variable*> : set that will be filled 
		* @param onlyUsed : true if you only want assigment and write variables
		*/
		virtual void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const = 0;

		/*
		* Returns a variable if the instruction was an assignment
		*/
		virtual Variable* GetAssignedVar() const;

		virtual Variable* GetModifiedVariable(void) const;

		/*
		 * Returns whether the instruction may be deleted by another one or not
		 */
		bool MayBeDeleted(void) const;
};

#endif //_INSTRUCTION_H

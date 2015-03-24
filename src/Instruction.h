/**
 * Project Lutin
 */


#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <string>
#include <set>
#include <map>

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
		* Returns the variables used in the instruction if they were assigned (assignment and read operations)
		*/
		virtual Variable* GetAssignedVar() const;

		/*
		 * Returns whether the instruction may be deleted by another one or not
		 */
		bool MayBeDeleted(void) const;
		void Protect(void);
		void Unprotect(void);

		virtual Instruction *Optimize(std::map<Variable*, int> & varKnown);

	private:
		bool protectedFromDeletion;
};

#endif //_INSTRUCTION_H

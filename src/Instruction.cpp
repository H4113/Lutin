/**
 * Project Lutin
 */


#include "Instruction.h"

/**
 * Instruction implementation
 */
 
Instruction::Instruction():
	protectedFromDeletion(false)
{
}

Instruction::~Instruction()
{
}

Variable* Instruction::GetAssignedVar() const
{
	return 0;
}

bool Instruction::MayBeDeleted(void) const
{
	InstruType t = GetInstructionType();
	return GetInstructionType() == IT_VAL 
		|| (!protectedFromDeletion 
			&& t != IT_VAR && t != IT_CON);
}

void Instruction::Protect(void)
{
	protectedFromDeletion = true;
}

void Instruction::Unprotect(void)
{
	protectedFromDeletion = false;
}


/**
 * Project Lutin
 */


#include "Instruction.h"

/**
 * Instruction implementation
 */
 
Instruction::Instruction()
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
	return t != IT_VAR && t != IT_CON;
}

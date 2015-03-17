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

Variable* Instruction::GetAssignedVar() const
{
	return 0;
}

Variable* Instruction::GetModifiedVariable(void) const
{
	return 0;
}

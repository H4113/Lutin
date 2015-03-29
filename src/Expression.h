/**
 * Project Lutin
 */


#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Instruction.h"

/**
 *	@class Expression
 *  @brief An abstract class which can be executed to give a value.
 */
class Expression : public Instruction
{
	public:
		Expression();
		virtual ~Expression();
		
		//Override
		virtual void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const = 0;
};

#endif //_EXPRESSION_H

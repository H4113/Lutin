/**
 * Project Lutin
 */


#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Instruction.h"


class Expression : public Instruction
{
	public:
		//Override
		virtual void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const = 0;
	protected:
		Expression();
};

#endif //_EXPRESSION_H

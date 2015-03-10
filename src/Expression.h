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
		virtual void GetVariables(std::set<const Variable*> &set) const = 0;
	protected:
		Expression(bool p = false);
		bool parenthesis;
};

#endif //_EXPRESSION_H

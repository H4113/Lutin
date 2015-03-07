/**
 * Project Lutin
 */


#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

 #include <string>

class Instruction 
{
	public: 
		Instruction();
		virtual int execute(void) = 0;
		
		virtual void display(void) const = 0;

		virtual std::string toString(void) const = 0;
};

#endif //_INSTRUCTION_H

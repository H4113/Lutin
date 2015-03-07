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
		virtual int Execute(void) = 0;
		
		virtual void Display(void) const = 0;

		virtual std::string ToString(void) const = 0;
};

#endif //_INSTRUCTION_H

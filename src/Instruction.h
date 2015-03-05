/**
 * Project Lutin
 */


#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

 #include <string>

class Instruction {
	public: 
		Instruction();
		virtual int execute() = 0;
		
		virtual void display() const = 0;

		virtual std::string toString() const = 0;
};

#endif //_INSTRUCTION_H

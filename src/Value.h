/**
 * Project Lutin
 */


#ifndef _VALUE_H
#define _VALUE_H

#include "Element.h"
#include <string>

/**
 *	@class Value
 *  @brief Represent a number hardcoded in the program
 */
class Value: public Element 
{
	public:
		Value();
		Value(int);
		virtual ~Value();

		/**
		 *	Display the code corresponding to the constant.
		 */ 
		void Display() const;

		/**
		 *	Creates a string representing the value
		 *	@return the string created
		 */
		std::string ToString(void) const;

		//Override
		void GetVariables(std::set<const Variable*> &set, bool) const;

		//@Override
		InstruType GetInstructionType(void) const;
};

#endif //_VALUE_H

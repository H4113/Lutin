/**
 * Project Lutin
 */


#ifndef _CONSTANT_H
#define _CONSTANT_H

#include "Variable.h"
#include <iostream>
#include <string>

/**
 *	@class Constant
 *	A variable with a value initialized with constructor and that can not be changed
 */
class Constant: public Variable 
{
	public: 
		
		/**
		 * @param value used to initilize the constant
		 */
		Constant(const std::string&, const int& value);

		/**
		 *	Display the code corresponding to the constant.
		 */ 
		void Display(void) const;

		/**
		 *	Indicates if the variable is a constant
		 *	@return true
		 */
		bool IsConstant(void) const;

		/**
		 *	Creates a string representing the declaration of the constant
		 *	@return the string created
		 */
		std::string GetDeclaration(void) const;

		//@Override
		InstruType GetInstructionType() const;
};

#endif //_CONSTANT_H

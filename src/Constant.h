/**
 * Project Lutin
 */


#ifndef _CONSTANT_H
#define _CONSTANT_H

#include "Variable.h"
#include <iostream>

/**
 *	@class Constant
 *	A variable with a value initialized with constructor and that can not be changed
 */
class Constant: public Variable {
	public: 
		
		/**
		 * @param value used to initilize the constant
		 */
		Constant(const int& value);

		/**
		 *	Display the code corresponding to the constant.
		 */ 
		void display() const;

		/**
		 *	Creates a string representing the constant
		 *	@return the string created
		 */
		std::string toString() const;
};

#endif //_CONSTANT_H

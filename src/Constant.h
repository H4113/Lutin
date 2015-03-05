/**
 * Project Lutin
 */


#ifndef _CONSTANT_H
#define _CONSTANT_H

#include "Variable.h"

/**
 *	@class Constant
 *	A variable with a value initialized with constructor and that can not be changed
 */
class Constant: public Variable {
	public: 
		
		/**
		 * @param value
		 */
		Constant(const int& value);
};

#endif //_CONSTANT_H

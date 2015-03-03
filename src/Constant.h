/**
 * Project Lutin
 */


#ifndef _CONSTANT_H
#define _CONSTANT_H

#include "Variable.h"


class Constant: public Variable {
	public: 
		
		/**
		 * @param value
		 */
		Constant(const int& value);
};

#endif //_CONSTANT_H

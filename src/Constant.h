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
	Constant(int value);
};

#endif //_CONSTANT_H
/**
 * Project Lutin
 */


#ifndef _ELEMENT_H
#define _ELEMENT_H

#include "Expression.h"


class Element: public Expression {
	public:
		/**
		 * @param value
		 */
		bool set(int value);
		
		int get();
	protected:
		int* pointer;
};

#endif //_ELEMENT_H
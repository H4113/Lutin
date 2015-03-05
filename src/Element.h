/**
 * Project Lutin
 */


#ifndef _ELEMENT_H
#define _ELEMENT_H

#include "Expression.h"

/**
 *	@class Element
 *	An expression representing a specific value
 */
class Element: public Expression {
	public:
		/**
		 * @param value
		 */
		bool set(int value);
		
		int get();
	protected:
		// The value
		int* pointer;
};

#endif //_ELEMENT_H

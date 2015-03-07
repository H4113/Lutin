/**
 * Project Lutin
 */


#ifndef _VALUE_H
#define _VALUE_H

#include "Element.h"
#include <string>

class Value: public Element 
{
	public:
		/**
		 *	Display the code corresponding to the constant.
		 */ 
		void display(void) const;

		/**
		 *	Creates a string representing the value
		 *	@return the string created
		 */
		std::string toString(void) const;
};

#endif //_VALUE_H

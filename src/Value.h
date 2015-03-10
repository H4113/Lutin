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
		Value(bool p = false);
		
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
		void GetVariables(std::set<const Variable*> &set) const
		{
			//Does nothing
			(void)set;
		};
};

#endif //_VALUE_H

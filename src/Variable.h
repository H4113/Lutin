/**
 * Project Lutin
 */


#ifndef _VARIABLE_H
#define _VARIABLE_H

#include <string>

#include "Element.h"


class Variable: public Element 
{
	public: 
		Variable(const std::string&);

		/**
		 *	@return name
		 */
		std::string getName(void) const;

		/**
		 *	Display the code corresponding to the variable.
		 */ 
		void display(void) const;

		/**
		 *	@return initialized
		 */
		bool getInitialized(void) const;

		/**
		 *	Creates a string representing the variable
		 *	@return the string created
		 */
		std::string toString(void) const;
	protected: 
		std::string name;
	private: 
		bool initialized;
};

#endif //_VARIABLE_H

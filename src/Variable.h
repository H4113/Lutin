/**
 * Project Lutin
 */


#ifndef _VARIABLE_H
#define _VARIABLE_H

#include <string>

#include "Element.h"


class Variable: public Element {
	public: 
		Variable();

		/**
		 *	@return name
		 */
		std::string getName() const;

		/**
		 *	Display the code corresponding to the variable.
		 */ 
		void display() const;

		/**
		 *	@return initialized
		 */
		bool getInitialized() const;

		/**
		 *	Creates a string representing the variable
		 *	@return the string created
		 */
		std::string toString() const;
	protected: 
		std::string name;
	private: 
		bool initialized;
};

#endif //_VARIABLE_H

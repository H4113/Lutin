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
		std::string GetName(void) const;

		/**
		 *	Display the code corresponding to the variable.
		 */ 
		virtual void Display(void) const;

		/**
		 *	@return initialized
		 */
		bool GetInitialized(void) const;

		/**
		 *	Creates a string representing the variable
		 *	@return the string created
		 */
		virtual std::string ToString(void) const;

		/**
		 *	Creates a string representing the declaration of the variable
		 *	@return the string created
		 */
		virtual std::string GetDeclaration(void) const;

		//Override
		void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const;
	protected: 
		std::string name;
	private:
		//May be unused 
		bool initialized;
};

#endif //_VARIABLE_H

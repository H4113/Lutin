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
		Variable(const std::string&, bool g=false);
		virtual ~Variable();

		/**
		 *	@return name
		 */
		std::string GetName(void) const;

		/**
		 *	Display the code corresponding to the variable.
		 */ 
		virtual void Display(void) const;

		/**
		 *	@return ghost
		 */
		bool GetGhost(void) const;

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

		/**
		 *	Indicates if the variable is a constant
		 *	@return false
		 */
		virtual bool IsConstant(void) const;

		//Override
		void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const;

		//@Override
		InstruType GetInstructionType(void) const;
	protected: 
		std::string name;
	private:
		//True if variable is used but not declared 
		bool ghost;
};

#endif //_VARIABLE_H

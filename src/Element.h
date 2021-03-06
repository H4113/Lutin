/**
 * Project Lutin
 */


#ifndef _ELEMENT_H
#define _ELEMENT_H

#include "Expression.h"

/**
 *	@class Element
 *	@brief An expression representing a specific value
 */
class Element: public Expression 
{
	public:
		Element();
		virtual ~Element();
		/**
		 * @param value The new value
		 */
		bool Set(int value);
		
		/**
		 * @return the current value
		 */
		int Get(void);

		/**
		 *	@return the int value of the constant
		 */
		int Execute(void);

		//Override
		virtual void GetVariables(std::set<const Variable*> &set, bool onlyUsed = false) const = 0;
	protected:
		int value;
};

#endif //_ELEMENT_H

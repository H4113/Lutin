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
	protected: 
		std::string name;
	private: 
		bool initialized;
};

#endif //_VARIABLE_H

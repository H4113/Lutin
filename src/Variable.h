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
	 * @param value
	 */
	bool set(int value);
	
	int get();
protected: 
	std::string name;
	int* pointer;
private: 
	bool initialized;
};

#endif //_VARIABLE_H

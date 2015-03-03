/**
 * Project Lutin
 */


#ifndef _VARIABLE_H
#define _VARIABLE_H

#include "Element.h"


class Variable: public Element {
public: 
	
	void Variable();
	
	/**
	 * @param value
	 */
	bool set(int value);
	
	int get();
protected: 
	string name;
	int* pointer;
private: 
	bool initialized;
};

#endif //_VARIABLE_H
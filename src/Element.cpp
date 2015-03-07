/**
 * Project Lutin
 */
#include "Element.h"

/**
 * Element implementation
 */

 Element::Element() 
 {
 	
 }

/**
 * @param value
 * @return bool
 */
bool Element::set(int value) 
{
	*pointer = value;
	return true;
}

/**
 * @return int
 */
int Element::get(void) 
{
	return *pointer;
}

int Element::execute(void) 
{
	return *pointer;
}

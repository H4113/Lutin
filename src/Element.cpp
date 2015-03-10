/**
 * Project Lutin
 */
#include "Element.h"

/**
 * Element implementation
 */

 Element::Element() 
 {
 	pointer = new int();
 }

 Element::~Element()
 {
 	delete pointer;
 }

/**
 * @param value
 * @return bool
 */
bool Element::Set(int value) 
{
	*pointer = value;
	return true;
}

/**
 * @return int
 */
int Element::Get(void) 
{
	return *pointer;
}

int Element::Execute(void) 
{
	return *pointer;
}

/**
 * Project Lutin
 */
#include "Element.h"

/**
 * Element implementation
 */

 Element::Element():
	 value(0)
 {
 }

 Element::~Element()
 {
 }

/**
 * @param value
 * @return bool
 */
bool Element::Set(int val) 
{
	value = val;
	return true;
}

/**
 * @return int
 */
int Element::Get(void) 
{
	return value;
}

int Element::Execute(void) 
{
	return value;
}


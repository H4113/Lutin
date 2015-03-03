/**
 * Project Lutin
 */


#include "Element.h"

/**
 * Element implementation
 */

/**
 * @param value
 * @return bool
 */
bool Element::set(int value) {
	*pointer = value;
	return true;
}

/**
 * @return int
 */
int Element::get() {
	return *pointer;
}

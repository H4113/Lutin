/**
 * Project Lutin
 */

#ifndef _RULES_H
#define _RULES_H

#include "Symbol.h"

#define RULE_COUNT 22

/** Rule
 *  @brief Represent a grammar rule. Used to know the number of 
 *  elements of a right part of a grammar rule.
 */
typedef struct Rule 
{
	Symbol leftPart;
	unsigned int rightPartCount;
} Rule;

extern const Rule RULES[RULE_COUNT];

#endif //_RULES_H

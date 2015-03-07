/**
 * Project Lutin
 */

#ifndef _RULES_H
#define _RULES_H

#include "Symbol.h"

#define RULE_COUNT 22

typedef struct Rule {
	Symbol leftPart;
	unsigned int rightPartCount;
} Rule;

extern const Rule RULES[RULE_COUNT];

#endif //_RULES_H

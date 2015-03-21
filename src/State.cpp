/**
 * Project Lutin
 */


#include "State.h"

/**
 * State implementation
 */

State::State()
{
}

State::~State()
{
}

const std::vector<Symbol> &State::GetExpectedTerminals(void) const
{
	return expectedTerminals;
}


/**
 * Project Lutin
 */


#ifndef _STATE_H
#define _STATE_H

#include <vector>

#include "Word.h"

class Automaton;

enum StateResult 
{
	SR_TRANSITION,
	SR_ACCEPT,
	SR_ERROR
};

/**
 *	@class State
 *  @brief State of the Automaton
 */
class State
{
	public: 
		State();
		virtual ~State();

		/**
		 * @param automaton
		 * @param word The current word read
		 */
		virtual StateResult Transition(Automaton* automaton, Word *word) = 0;
		/**
		 * @Return the expected following terminal symbols
		 */
		const std::vector<Symbol> &GetExpectedTerminals(void) const;

	protected:
		std::vector<Symbol> expectedTerminals;
};

#endif //_STATE_H

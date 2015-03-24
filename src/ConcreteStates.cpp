/**
 * Project Lutin
 */

#include "ConcreteStates.h"
#include "Automaton.h"

State00::State00() :
	State()
{
	expectedTerminals.push_back(SYM_v);
	expectedTerminals.push_back(SYM_c);
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_w);
	expectedTerminals.push_back(SYM_r);
	expectedTerminals.push_back(SYM_end);
}

State00::~State00() 
{
}

StateResult State00::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_v:
		case SYM_c:
		case SYM_id:
		case SYM_w:
		case SYM_r:
		case SYM_end:
			return automaton->Reduce(3);
		
		case SYM_P:
			automaton->Shift(word, new State01());
			return SR_TRANSITION;

		case SYM_Pd:
			automaton->Shift(word, new State02());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State01::State01() :
	State()
{
	expectedTerminals.push_back(SYM_end);
}

State01::~State01() 
{
}

StateResult State01::Transition(Automaton*, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_end:
			return SR_ACCEPT;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State02::State02() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_w);
	expectedTerminals.push_back(SYM_r);
	expectedTerminals.push_back(SYM_end);
	expectedTerminals.push_back(SYM_v);
	expectedTerminals.push_back(SYM_c);
}

State02::~State02() 
{
}

StateResult State02::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
		case SYM_w:
		case SYM_r:
		case SYM_end:
			return automaton->Reduce(11);

		case SYM_v:
			automaton->Shift(word, new State05());
			return SR_TRANSITION;
		
		case SYM_c:
			automaton->Shift(word, new State06());
			return SR_TRANSITION;

		case SYM_Pi:
			automaton->Shift(word, new State04());
			return SR_TRANSITION;

		case SYM_D:
			automaton->Shift(word, new State03());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State03::State03() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
}

State03::~State03() 
{
}

StateResult State03::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_pv:
			automaton->Shift(word, new State07());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State04::State04() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_w);
	expectedTerminals.push_back(SYM_r);
	expectedTerminals.push_back(SYM_end);
}

State04::~State04() 
{
}

StateResult State04::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_id:
			automaton->Shift(word, new State10());
			return SR_TRANSITION;

		case SYM_w:
			automaton->Shift(word, new State11());
			return SR_TRANSITION;

		case SYM_r:
			automaton->Shift(word, new State08());
			return SR_TRANSITION;

		case SYM_end:
			return automaton->Reduce(1);

		case SYM_I:
			automaton->Shift(word, new State09());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State05::State05() :
	State()
{
	expectedTerminals.push_back(SYM_id);
}

State05::~State05() 
{
}

StateResult State05::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_id:
			automaton->Shift(word, new State16());
			return SR_TRANSITION;

		case SYM_Lval:
			automaton->Shift(word, new State21());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State06::State06() :
	State()
{
	expectedTerminals.push_back(SYM_id);
}

State06::~State06() 
{
}

StateResult State06::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_id:
			automaton->Shift(word, new State18());
			return SR_TRANSITION;

		case SYM_Lconst:
			automaton->Shift(word, new State13());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State07::State07() :
	State()
{
}

State07::~State07() 
{
	expectedTerminals.push_back(SYM_v);
	expectedTerminals.push_back(SYM_c);
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_w);
	expectedTerminals.push_back(SYM_r);
	expectedTerminals.push_back(SYM_end);
}
StateResult State07::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_v:
		case SYM_c:
		case SYM_id:
		case SYM_w:
		case SYM_r:
		case SYM_end:
			return automaton->Reduce(2);
		
		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State08::State08() :
	State()
{
	expectedTerminals.push_back(SYM_id);
}

State08::~State08() 
{
}

StateResult State08::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_id:
			automaton->Shift(word, new State12());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State09::State09() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
}

State09::~State09() 
{
}

StateResult State09::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_pv:
			automaton->Shift(word, new State17());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State10::State10() :
	State()
{
	expectedTerminals.push_back(SYM_aff);
}

State10::~State10() 
{
}

StateResult State10::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_aff:
			automaton->Shift(word, new State38());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State11::State11() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State11::~State11() 
{
}

StateResult State11::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State24());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State12::State12() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
}

State12::~State12() 
{
}

StateResult State12::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_pv:
			return automaton->Reduce(13);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State13::State13() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_vg);
}

State13::~State13() 
{
}

StateResult State13::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_pv:
			return automaton->Reduce(5);

		case SYM_vg:
			automaton->Shift(word, new State14());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State14::State14() :
	State()
{
	expectedTerminals.push_back(SYM_id);
}

State14::~State14() 
{
}

StateResult State14::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_id:
			automaton->Shift(word, new State18());
			return SR_TRANSITION;

		case SYM_Lconst:
			automaton->Shift(word, new State15());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State15::State15() :
	State()
{
}

State15::~State15() 
{
}

StateResult State15::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_pv:
			return automaton->Reduce(9);

		case SYM_vg:
			automaton->Shift(word, new State14());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State16::State16() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_vg);
}

State16::~State16() 
{
}

StateResult State16::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol())
	{
		case SYM_pv:
		case SYM_vg:
			return automaton->Reduce(6);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State17::State17() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_w);
	expectedTerminals.push_back(SYM_r);
	expectedTerminals.push_back(SYM_end);
}

State17::~State17() 
{
}

StateResult State17::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
		case SYM_w:
		case SYM_r:
		case SYM_end:
			return automaton->Reduce(10);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State18::State18() :
	State()
{
	expectedTerminals.push_back(SYM_eq);
}

State18::~State18() 
{
}

StateResult State18::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_eq:
			automaton->Shift(word, new State19());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State19::State19() :
	State()
{
	expectedTerminals.push_back(SYM_n);
}

State19::~State19() 
{
}

StateResult State19::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_n:
			automaton->Shift(word, new State20());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State20::State20() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_vg);
}

State20::~State20() 
{
}

StateResult State20::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_vg:
			return automaton->Reduce(8);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State21::State21() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_vg);
}

State21::~State21() 
{
}

StateResult State21::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
			return automaton->Reduce(4);

		case SYM_vg:
			automaton->Shift(word, new State22());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State22::State22() :
	State()
{
	expectedTerminals.push_back(SYM_id);
}

State22::~State22() 
{
}

StateResult State22::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State23());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State23::State23() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_vg);
}

State23::~State23() 
{
}

StateResult State23::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_vg:
			return automaton->Reduce(7);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State24::State24() :
	State()
{
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_pv);
}

State24::~State24() 
{
}

StateResult State24::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_plus:
			automaton->Shift(word, new State28());
			return SR_TRANSITION;

		case SYM_times:
			automaton->Shift(word, new State34());
			return SR_TRANSITION;

		case SYM_minus:
			automaton->Shift(word, new State32());
			return SR_TRANSITION;

		case SYM_div:
			automaton->Shift(word, new State36());
			return SR_TRANSITION;

		case SYM_pv:
			return automaton->Reduce(12);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State25::State25() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

State25::~State25() 
{
}

StateResult State25::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_times:
		case SYM_minus:
		case SYM_div:
		case SYM_cl_par:
			return automaton->Reduce(20);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State26::State26() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

State26::~State26() 
{
}

StateResult State26::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_times:
		case SYM_minus:
		case SYM_div:
		case SYM_cl_par:
			return automaton->Reduce(21);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State27::State27() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State27::~State27() 
{
}

StateResult State27::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State30());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State28::State28() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State28::~State28() 
{
}

StateResult State28::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State29());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State29::State29() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

State29::~State29() 
{
}

StateResult State29::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_minus:
		case SYM_cl_par:
			return automaton->Reduce(15);

		case SYM_times:
			automaton->Shift(word, new State34());
			return SR_TRANSITION;

		case SYM_div:
			automaton->Shift(word, new State36());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State30::State30() :
	State()
{
}

State30::~State30() 
{
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

StateResult State30::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_plus:
			automaton->Shift(word, new State28());
			return SR_TRANSITION;

		case SYM_times:
			automaton->Shift(word, new State34());
			return SR_TRANSITION;

		case SYM_minus:
			automaton->Shift(word, new State32());
			return SR_TRANSITION;

		case SYM_div:
			automaton->Shift(word, new State36());
			return SR_TRANSITION;

		case SYM_cl_par:
			automaton->Shift(word, new State31());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State31::State31() :
	State()
{
}

State31::~State31() 
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

StateResult State31::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_times:
		case SYM_minus:
		case SYM_div:
		case SYM_cl_par:
			return automaton->Reduce(19);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State32::State32() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State32::~State32() 
{
}

StateResult State32::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State33());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State33::State33() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

State33::~State33() 
{
}

StateResult State33::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_minus:
		case SYM_cl_par:
			return automaton->Reduce(17);

		case SYM_times:
			automaton->Shift(word, new State34());
			return SR_TRANSITION;

		case SYM_div:
			automaton->Shift(word, new State36());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State34::State34() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State34::~State34() 
{
}

StateResult State34::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State35());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State35::State35() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

State35::~State35() 
{
}

StateResult State35::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_times:
		case SYM_minus:
		case SYM_div:
		case SYM_cl_par:
			return automaton->Reduce(16);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State36::State36() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State36::~State36() 
{
}

StateResult State36::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State37());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State37::State37() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
	expectedTerminals.push_back(SYM_cl_par);
}

State37::~State37() 
{
}

StateResult State37::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
		case SYM_plus:
		case SYM_times:
		case SYM_minus:
		case SYM_div:
		case SYM_cl_par:
			return automaton->Reduce(18);

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State38::State38() :
	State()
{
	expectedTerminals.push_back(SYM_id);
	expectedTerminals.push_back(SYM_n);
	expectedTerminals.push_back(SYM_op_par);
}

State38::~State38() 
{
}

StateResult State38::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_id:
			automaton->Shift(word, new State25());
			return SR_TRANSITION;

		case SYM_n:
			automaton->Shift(word, new State26());
			return SR_TRANSITION;

		case SYM_op_par:
			automaton->Shift(word, new State27());
			return SR_TRANSITION;

		case SYM_E:
			automaton->Shift(word, new State39());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}

// ----------------------------------------------------------------

State39::State39() :
	State()
{
	expectedTerminals.push_back(SYM_pv);
	expectedTerminals.push_back(SYM_plus);
	expectedTerminals.push_back(SYM_times);
	expectedTerminals.push_back(SYM_minus);
	expectedTerminals.push_back(SYM_div);
}

State39::~State39() 
{
}

StateResult State39::Transition(Automaton* automaton, Word *word) 
{
	switch(word->GetSymbol()) 
	{
		case SYM_pv:
			return automaton->Reduce(14);

		case SYM_plus:
			automaton->Shift(word, new State28());
			return SR_TRANSITION;

		case SYM_times:
			automaton->Shift(word, new State34());
			return SR_TRANSITION;

		case SYM_minus:
			automaton->Shift(word, new State32());
			return SR_TRANSITION;

		case SYM_div:
			automaton->Shift(word, new State36());
			return SR_TRANSITION;

		default:
			break;
	}
	return SR_ERROR;
}


#ifndef FSM_H
#define FSM_H

#include "systemc.h"
#include "macros.h"

SC_MODULE (FSM) {
	sc_in <bool> clock;
	sc_out < sc_bv<4> > state;
	sc_in <sc_bv<4> > nextstate;
	sc_out <sc_bv<24> >instr;
	

	void fsm_thread (void);

	SC_CTOR (FSM) {
		SC_THREAD (fsm_thread);
		sensitive << clock.pos();
	}
};

#endif

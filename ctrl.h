#ifndef CTRL_H_INCLUDED
#define CTRL_H_INCLUDED

#include "macros.h"

SC_MODULE(CTRL) {
	
	// Ports
        sc_in< sc_bv<8> > Opcode;       // opcodes in the instruction 
	sc_in< bool > clk;
        sc_out< sc_bv<1> > ALE;
        sc_out< sc_bv<1> > IO_M;
        sc_out< sc_bv<1> > S0;
        sc_out< sc_bv<1> > S1;
        sc_out< sc_bv<1> > RD;
        sc_out< sc_bv<1> > WR;
        sc_out< sc_bv<1> > ALUctrl;
        sc_out< sc_bv<4> > NextState;
	sc_in< sc_bv<4> > State;

	void ctrl_thread(void);

	// Constructor
	SC_CTOR(CTRL) {
		SC_THREAD(ctrl_thread);
		sensitive<<State;
		sensitive<<clk.pos();

	}
};

#endif

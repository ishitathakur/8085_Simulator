#ifndef ALUCTRL_H_INCLUDED
#define ALUCTRL_H_INCLUDED

#include "macros.h"

SC_MODULE(ALUCTRL)
{	sc_in< sc_bv<8> > ALUop;	
	sc_out< sc_bv<3> > ALUctrl;	// Control output to ALU

	void aluctrl_thread(void);

	// Constructor
	SC_CTOR(ALUCTRL) {
		SC_THREAD(aluctrl_thread);
		sensitive << ALUop;
	}
};

#endif

#ifndef DECODER_H_INCLUDED
#define DECODER_H_INCLUDED

#include "macros.h"

SC_MODULE(DECODER) {
	sc_in< sc_bv<24> > instr;
	sc_out< sc_bv<8> > instr_23_16;
	sc_out< sc_bv<8> > instr_15_8;	
	sc_out< sc_bv<8> > instr_7_0;	

	void decoder_thread(void);
	
	SC_CTOR(DECODER) {
		SC_THREAD(decoder_thread);
		sensitive << instr;
	}
};

#endif

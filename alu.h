#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

#include "macros.h"
 
SC_MODULE(ALU) {
	sc_in< sc_bv<3> >	ctrl;	// Control input
	sc_in< sc_bv<1> >       aluflag;	//Alu write enabled
	sc_inout<  sc_bv<8> >	acc;	// First operand input 
	sc_in<  sc_bv<8> >	b;	// Second operand input
	sc_out< sc_bv<8> >psw;	// Praogram status word set according to the contents in alu

	void alu_thread(void);

	// Constructor
	SC_CTOR(ALU) {
		SC_THREAD(alu_thread);
		sensitive << ctrl;
		sensitive << acc;
		sensitive << b;
		sensitive<<aluflag;
	}
};

#endif

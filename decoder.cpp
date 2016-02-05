#include "decoder.h"

void
DECODER::
decoder_thread(void)
{
	sc_uint<24> t_instr;
	sc_uint<8> t_instr_23_16;
	sc_uint<8> t_instr_15_8;
	sc_uint<8> t_instr_7_0;

	while (true)
	 {
		// Read input
		t_instr = instr.read();
		
		// Compute output
		t_instr_23_16 = t_instr.range(23,16);
		t_instr_15_8 = t_instr.range(15,8);
		t_instr_7_0 = t_instr.range(7,0);
		
		// Write output
		instr_23_16.write(t_instr_23_16);
		instr_15_8.write(t_instr_15_8);
		instr_7_0.write(t_instr_7_0);

		// Wait for next event
		wait();
	}
}

#include "registerfile1.h"
void REGFILE:: regfile_read_thread(void)
{	sc_uint<16>	a_wreg;
	sc_uint<16>	a_reg1;
	sc_uint<16>	a_reg2;
	sc_uint<8>	d_wreg;
	sc_uint<1>	w_t;
	bool		clk_t;
while (true) {

		clk_t = clk.read();

		if (clk_t == 1) {
			a_reg1 = r_addr_reg1.read();
			a_reg2 = r_addr_reg2.read();
			r_data_reg1.write(rfile[a_reg1]);
			r_data_reg2.write(rfile[a_reg2]);
			
		}
		wait();
	}
}

void REGFILE:: regfile_write_thread(void)
{	sc_uint<16>	a_wreg;
	sc_uint<16>	a_reg1;
	sc_uint<16>	a_reg2;
	sc_uint<8>		d_wreg;
	sc_uint<1>		w_t;
	while(true) {
		w_t = w.read();
		if (w_t == 1) {
			a_wreg = w_addr_reg.read();
			d_wreg = w_data_reg.read();
			
			if (a_wreg < REGSIZE && a_wreg != 0) {
				rfile[a_wreg] = d_wreg;
			}
		}
		wait();
	}
}

void
REGFILE::
regfile_init(void)
{
	rfile[0] = 0;
}

#include "aluctrl.h"

void
ALUCTRL::
aluctrl_thread(void)
{
	sc_uint<3> aluCtrl;
	sc_uint<8> aluop;
	while (true)
	 {	cerr << "ALUCTRL" << endl;

		// Determine output
		aluop = ALUop.read();

		switch (aluop) 
		{
			case OP_ADD:	// Add
                        aluCtrl = ALU_ADD;
                        break;

			case OP_SUB:	// Subtract
                        aluCtrl = ALU_SUB;
                        break;

			case OP_ANA:	// AND 
                        aluCtrl = ALU_AND;
                        break;

			case OP_ORA:	// OR
                        aluCtrl = ALU_OR;
                        break;
		}
		// Set result on output
		ALUctrl.write(aluCtrl);

		// Wait for new event
		wait();
	}
}

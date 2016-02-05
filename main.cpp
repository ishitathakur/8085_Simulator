#include "alu.h"
#include "registerfile1.h"
#include "decoder.h"
#include "ctrl.h"
#include "aluctrl.h"
#include "macros.h"
#include "fsm.h"
#include "register.h"

int
sc_main(int argc, char* argv[])
{
   	//char stbuf[256];
	sc_report_handler::
	set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);

		//Data Signals 
	 sc_signal< sc_bv<4> > bus_state;
	 sc_signal< sc_bv<4> > bus_nextstate;
	 sc_signal< sc_bv<24> > bus_instr;
	 sc_signal< sc_bv<8> > bus_opcode;
	 sc_signal< sc_bv<8> > bus_decoder_15_8;
	 sc_signal< sc_bv<8> > bus_decoder_7_0;
	
		//Control Signals
          sc_signal< sc_bv<1> >ctrl_ALE;
	  sc_signal< sc_bv<1> >ctrl_IO_M;
	  sc_signal< sc_bv<1> >ctrl_S0;
	  sc_signal< sc_bv<1> >ctrl_S1;
	  sc_signal< sc_bv<1> >ctrl_RD;
	  sc_signal< sc_bv<1> >ctrl_WR;
	  sc_signal< sc_bv<1> >ctrl_ALUctrl;
	  sc_signal< sc_bv<3> >aluctrl_ALUctrl;
	  
	
		//Modules 
	DECODER decoder("decoder");
	CTRL ctrl("ctrl");
//	ALU alu("alu");
//	ALUCTRL aluctrl("aluctrl");
	FEEDER feed("feed");
	sc_clock clk("clock", 20);		// Clock
	cerr << " Modules OK \n";

	feed.clock(clk);
	feed.instr(bus_instr);
	feed.nextstate(bus_nextstate);
	feed.state(bus_state);

	decoder.instr(bus_instr);
	decoder.instr_23_16(bus_opcode);
	decoder.instr_15_8(bus_decoder_15_8);
	decoder.instr_7_0(bus_decoder_7_0);

	ctrl.clk(clk);
	ctrl.Opcode(bus_opcode);
	ctrl.State(bus_state);
	ctrl.ALE(ctrl_ALE);
	ctrl.IO_M(ctrl_IO_M);
	ctrl.S0(ctrl_S0);
	ctrl.S1(ctrl_S1);
	ctrl.RD(ctrl_RD);
	ctrl.WR(ctrl_WR);
	ctrl.ALUctrl(ctrl_ALUctrl);
	ctrl.NextState(bus_nextstate);


		// Tracing
	 sc_trace_file *tf;
	 tf = sc_create_vcd_trace_file("8085");
         cerr << " TraceFile OK\n";
	 sc_trace(tf, clk, "clock");
	 sc_trace(tf,ctrl_ALE, "ALE");
 	 sc_trace(tf,ctrl_IO_M, "IO_M");
	 sc_trace(tf,ctrl_S0, "S0");
	 sc_trace(tf,ctrl_S1, "S1");
	 sc_trace(tf,ctrl_RD, "RD");
	 sc_trace(tf,ctrl_WR, "WR");
	 sc_trace(tf,ctrl_ALUctrl, "ALUctrl");	 
	 sc_trace(tf,bus_state, "state");
	 sc_trace(tf,bus_nextstate, "next_state");


	// Simulation
	int sim_time = 200;
//	if (argc == 2)
//		sim_time = atoi(argv[1]);

	sc_start(sim_time, SC_NS);
	cerr << " Simulation OK\n";

	sc_close_vcd_trace_file(tf);
	

	return 0;

}

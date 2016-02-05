#include "ctrl.h"

void CTRL::
ctrl_thread(void)
{ 	sc_uint<8> opcode;
	sc_uint<4> state;
       while(true)
       {	wait();//wait for the new event	
		opcode = Opcode.read();
		state = State.read();
		switch(state)
		{	case 0:					//Opcode Fetch Machine Cycle 
			ALE.write(1);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			NextState.write(1);			
			break;		
		
			case 1:
			ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(1);
			RD.write(0);
			WR.write(1);
			NextState.write(2);
			break;

			case 2:
			ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(1);
			RD.write(0);
			WR.write(1);
			NextState.write(3);
			break;

			case 3:
			ALE.write(0);
			IO_M.write(0);
			S0.write(1);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			  switch(opcode)
				{
					case OP_LDA:
						NextState.write(4);
						ALUctrl.write(0);
						break;
					case OP_STA:
						NextState.write(4);
						ALUctrl.write(0);
						break;
					case OP_J:
						NextState.write(4);
						ALUctrl.write(0);
						break;
						
					case OP_ADD:
					case OP_SUB:
					case OP_ANA:
					case OP_ORA:
					NextState.write(0);
					ALUctrl.write(1);
					break;
					
					case OP_MOV:
					NextState.write(0);
					ALUctrl.write(0);
					/*case OP_JZ:
					NextState.write();
					break;*/
                         	}
			break;
 			
		case 4: 							//Memory Read 
			ALE.write(1);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			NextState.write(5);			
			break;
		case 5:	ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(0);
			WR.write(1);
			NextState.write(6);
			break;
 		case 6: ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			 switch (opcode) 
			{	case OP_LDA:NextState.write(7);
				break;
				case OP_STA:NextState.write(7);
				break;
				case OP_J:
				   NextState.write(7);
				break;
				
				default:
				break;
			}
			break;
		
		case 7: ALE.write(1);			//Memory REad 
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			NextState.write(8);			
			break;

		case 8: ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(0);
			WR.write(1);
			NextState.write(9);
			break;
		case 9:ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			 switch (opcode) 
			{	case OP_LDA:
				NextState.write(13);
				break;
				
				case OP_STA:
				    NextState.write(10);
				break;
				case OP_J:NextState.write(0);
				default:
				break;
			}
			break;
		case 10:ALE.write(1);    		//Mem Write Machine Cycle 
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(0);
			RD.write(1);
			WR.write(1);
			NextState.write(11);			
			break;
		case 11:ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(0);
			RD.write(1);
			WR.write(0);
			NextState.write(12);			
			break;
		case 12:ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(1);
			S1.write(0);
			RD.write(1);
			WR.write(0);
			NextState.write(0);	//to check the value of next state acc to the instruction  STA OR JZ OR JNZ		
			break;
		case 13:ALE.write(1);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(1);
			WR.write(1);
			NextState.write(14);			
			break;
               case 14: ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(0);
			WR.write(1);
			NextState.write(15);
			break;
              case 15:  ALE.write(0);
			IO_M.write(0);
			ALUctrl.write(0);
			S0.write(0);
			S1.write(1);
			RD.write(0);
			WR.write(1);
			NextState.write(0);
			break;
		}
		  
       }
  
} 

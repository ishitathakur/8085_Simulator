#include "alu.h"
 
void
ALU::
alu_thread(void)
{	sc_bv<9>    result;
	sc_bv<8>    flag;
	sc_uint<8>  s;
	sc_uint<8>  t;
	sc_uint<2>  ctrl_t;
	sc_uint<1>  aluflag_t;

	while (true) 
	{	
		#ifdef VERBOSE
		cerr << "ALU" << endl;
		#endif

		// Read the inputs
		s = acc.read();
		t = b.read();
		ctrl_t = ctrl.read();
		aluflag_t=aluflag.read();
		if(aluflag_t)
		// Calculate result using selected operation
		{
		  switch (ctrl_t) {
			case ALU_AND:// And
				result = s & t;
				break;
			case ALU_OR:// Or
				result = s | t;
				break;
			case ALU_ADD:// Add
				result = s + t;
				break;
			case ALU_SUB:// Subtract
				result = s - t;
				break;
			
		}


	//Calculate the results for the Program status word 
		//For carry bit 		
			flag.range(0,0)=result.range(8,8);		
 		
		//For The Parity Bit
	 		int i=0;
			for(int i=0;i<8;i++)
			  if(result.range(i,i)==1) 
				i++;
	                if(i%2==0)
	    		   flag.range(2,2)=1;
			else 
			   flag.range(2,2)=0;

		//For sign bit 
			  if(result.range(7,7)==1)
				flag.range(7,7)=1;
	 		   else 		
				flag.range(7,7)=0;

		//For zero bit
	        	  if(result.range(0,7)==0)
	        	     flag.range(6,6)=1;
	        	   else 
	        	   flag.range(6,6)=0;
 
		   	acc.write(result.range(0,7));
			psw.write(flag);
		}
		// Wait for next event
		wait();
	}
}

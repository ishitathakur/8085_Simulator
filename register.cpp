# include "register.h"

template <int W>
void
REGISTER<W>::reg_thread(void)
{
        if( w.read() == 1)
                out.write(in.read());
        else
                out.write(out.read());
}

void
dummy_register (void)
{
	REGISTER<16> TempRegister32("Temp16");
	REGISTER<8> TempRegister8("Temp8");
	REGISTER<4> TempRegister4("Temp8");
}

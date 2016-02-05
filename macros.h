#ifndef I8085_H_INCLUDED
#define I8085_H_INCLUDED

#include "systemc.h"


#define DWORD 16
 
#define ALU_AND 00
#define ALU_OR  01
#define ALU_ADD 02
#define ALU_SUB 03


#define OP_LDA 0x3A
#define OP_STA 0x32
#define OP_ADD 0x80
#define OP_SUB 0x90
#define OP_MOV 0x78


#define W_MEMWRITE 0x1


#endif 

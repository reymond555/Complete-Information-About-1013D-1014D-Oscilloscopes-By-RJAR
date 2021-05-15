//----------------------------------------------------------------------------------------------------------------------------------

#ifndef ARMV5TL_H
#define ARMV5TL_H

//----------------------------------------------------------------------------------------------------------------------------------

#include <sys/types.h>

//----------------------------------------------------------------------------------------------------------------------------------
//Thumb section

typedef union  tagARMV5TL_THUMB_INSTRUCTION  ARMV5TL_THUMB_INSTRUCTION;
typedef struct tagARMV5TL_INSTR_THUMB_BASE   ARMV5TL_INSTR_THUMB_BASE;
typedef struct tagARMV5TL_INSTR_THUMB_SHIFT0 ARMV5TL_INSTR_THUMB_SHIFT0;
typedef struct tagARMV5TL_INSTR_THUMB_SHIFT2 ARMV5TL_INSTR_THUMB_SHIFT2;
typedef struct tagARMV5TL_INSTR_THUMB_DPI0   ARMV5TL_INSTR_THUMB_DPI0;
typedef struct tagARMV5TL_INSTR_THUMB_DPR0   ARMV5TL_INSTR_THUMB_DPR0;
typedef struct tagARMV5TL_INSTR_THUMB_DP1    ARMV5TL_INSTR_THUMB_DP1;
typedef struct tagARMV5TL_INSTR_THUMB_DP2    ARMV5TL_INSTR_THUMB_DP2;
typedef struct tagARMV5TL_INSTR_THUMB_DP2S   ARMV5TL_INSTR_THUMB_DP2S;
typedef struct tagARMV5TL_INSTR_THUMB_LS2I   ARMV5TL_INSTR_THUMB_LS2I;
typedef struct tagARMV5TL_INSTR_THUMB_LS2R   ARMV5TL_INSTR_THUMB_LS2R;
typedef struct tagARMV5TL_INSTR_THUMB_LS3    ARMV5TL_INSTR_THUMB_LS3;
typedef struct tagARMV5TL_INSTR_THUMB_LSM    ARMV5TL_INSTR_THUMB_LSM;
typedef struct tagARMV5TL_INSTR_THUMB_B2     ARMV5TL_INSTR_THUMB_B2;
typedef struct tagARMV5TL_INSTR_THUMB_B6     ARMV5TL_INSTR_THUMB_B6;
typedef struct tagARMV5TL_INSTR_THUMB_B7     ARMV5TL_INSTR_THUMB_B7;

//----------------------------------------------------------------------------------------------------------------------------------


struct tagARMV5TL_INSTR_THUMB_BASE
{
  u_int32_t data:6;       //Instruction data
  u_int32_t op2:5;        //Extended opcode
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_SHIFT0
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rm:3;         //Source register
  u_int32_t sa:5;         //5 bits shift amount
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_SHIFT2
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rs:3;         //Shift amount register
  u_int32_t op2:5;        //Extra opcode
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_DPI0
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rn:3;         //Source register
  u_int32_t im:3;         //3 bits immediate data
  u_int32_t op2:2;        //Extra opcode for some type of instructions
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_DPR0
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rn:3;         //Source register
  u_int32_t rm:3;         //Second source register
  u_int32_t op2:2;        //Extra opcode for some type of instructions
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_DP1
{
  u_int32_t im:8;         //Immediate data
  u_int32_t rd:3;         //Destination register
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_DP2
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rm:3;         //Source register
  u_int32_t op2:5;        //Extra opcode for some type of instructions
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_DP2S
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rm:4;         //Source register
  u_int32_t h:1;          //High bit of rd
  u_int32_t op2:3;        //Extra opcode for some type of instructions
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_LS2I
{
  u_int32_t im:8;         //Immediate data
  u_int32_t rd:3;         //Destination register
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_LS2R
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rn:3;         //Source register
  u_int32_t rm:3;         //Second source register
  u_int32_t op2:2;        //Extra opcode for some type of instructions
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_LS3
{
  u_int32_t rd:3;         //Destination register
  u_int32_t rn:3;         //Source register
  u_int32_t im:5;         //5 bit immediate index
  u_int32_t l:1;          //Load / store bit
  u_int32_t b:1;          //byte / word bit
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_LSM
{
  u_int32_t rl:8;         //Register list
  u_int32_t rn:3;         //Base register
  u_int32_t l:1;          //Load / store bit
  u_int32_t nu:1;         //Not used
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_B2
{
  u_int32_t sbz:3;        //Should be zero
  u_int32_t rm:4;         //Register holding target address
  u_int32_t op2:4;        //Extra opcode for some type of instructions
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_B6
{
  u_int32_t im:8;         //signed immediate
  u_int32_t cond:4;       //Condition for execute
  u_int32_t op1:1;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

struct tagARMV5TL_INSTR_THUMB_B7
{
  u_int32_t im:11;        //signed immediate
  u_int32_t op1:2;        //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
};

union tagARMV5TL_THUMB_INSTRUCTION
{
  u_int16_t                  instr;       //Instruction register
  ARMV5TL_INSTR_THUMB_BASE   base;        //Base type for decoding
  ARMV5TL_INSTR_THUMB_SHIFT0 shift0;      //Instruction data for type 0 shift instructions
  ARMV5TL_INSTR_THUMB_SHIFT2 shift2;      //Instruction data for type 2 shift instructions
  ARMV5TL_INSTR_THUMB_DPI0   dpi0;        //Instruction data for type 0 immediate data processing instructions
  ARMV5TL_INSTR_THUMB_DPR0   dpr0;        //Instruction data for type 0 register data processing instructions
  ARMV5TL_INSTR_THUMB_DP1    dp1;         //Instruction data for type 1 data processing instructions
  ARMV5TL_INSTR_THUMB_DP2    dp2;         //Instruction data for type 2 data processing instructions
  ARMV5TL_INSTR_THUMB_DP2S   dp2s;        //Instruction data for type 2 special data processing instructions
  ARMV5TL_INSTR_THUMB_LS2I   ls2i;        //Instruction data for type 2 load store immediate indexed based instructions
  ARMV5TL_INSTR_THUMB_LS2R   ls2r;        //Instruction data for type 2 load store register based instructions
  ARMV5TL_INSTR_THUMB_LS3    ls3;         //Instruction data for type 3 load store instructions
  ARMV5TL_INSTR_THUMB_LSM    lsm;         //Instruction data for load store multiple instructions
  ARMV5TL_INSTR_THUMB_B2     b2;          //Instruction data for type 2 branch instructions
  ARMV5TL_INSTR_THUMB_B6     b6;          //Instruction data for type 6 branch instructions
  ARMV5TL_INSTR_THUMB_B6     b7;          //Instruction data for type 7 branch instructions
};

//----------------------------------------------------------------------------------------------------------------------------------
//Arm section

typedef struct tagARMV5TL_ADDRESS_MAP       ARMV5TL_ADDRESS_MAP;
typedef struct tagARMV5TL_INSTR_BASE        ARMV5TL_INSTR_BASE;
typedef struct tagARMV5TL_INSTR_MISC0       ARMV5TL_INSTR_MISC0;     //Miscellaneous instructions
typedef struct tagARMV5TL_INSTR_TYPE0       ARMV5TL_INSTR_TYPE0;
typedef struct tagARMV5TL_INSTR_TYPE1       ARMV5TL_INSTR_TYPE1;
typedef struct tagARMV5TL_INSTR_TYPE2       ARMV5TL_INSTR_TYPE2;
typedef struct tagARMV5TL_INSTR_TYPE3       ARMV5TL_INSTR_TYPE3;
typedef struct tagARMV5TL_INSTR_TYPE4       ARMV5TL_INSTR_TYPE4;
typedef struct tagARMV5TL_INSTR_TYPE5       ARMV5TL_INSTR_TYPE5;
typedef struct tagARMV5TL_INSTR_TYPE6       ARMV5TL_INSTR_TYPE6;
typedef struct tagARMV5TL_INSTR_TYPE7       ARMV5TL_INSTR_TYPE7;
typedef struct tagARMV5TL_INSTR_MUL         ARMV5TL_INSTR_MUL;        //Multiply instructions
typedef struct tagARMV5TL_INSTR_ELS         ARMV5TL_INSTR_ELS;        //Extra load and store instructions
typedef struct tagARMV5TL_INSTR_DPSI        ARMV5TL_INSTR_DPSI;       //Data processing shift immediate instructions
typedef struct tagARMV5TL_INSTR_DPSR        ARMV5TL_INSTR_DPSR;       //Data processing shift register instructions
typedef struct tagARMV5TL_INSTR_DPI         ARMV5TL_INSTR_DPI;        //Data processing immediate instructions
typedef struct tagARMV5TL_INSTR_LSI         ARMV5TL_INSTR_LSI;        //Load and store immediate instructions
typedef struct tagARMV5TL_INSTR_LSR         ARMV5TL_INSTR_LSR;        //Load and store register instructions
typedef struct tagARMV5TL_INSTR_LSRN        ARMV5TL_INSTR_LSRN;       //Load and store register no scaling instructions
typedef struct tagARMV5TL_INSTR_LSX         ARMV5TL_INSTR_LSX;        //Load and store register extra instructions
typedef struct tagARMV5TL_INSTR_MSRI        ARMV5TL_INSTR_MSRI;       //Move immediate to status register instructions
typedef struct tagARMV5TL_INSTR_MSRR        ARMV5TL_INSTR_MSRR;       //Move register to status register instructions
typedef struct tagARMV5TL_INSTR_MRS         ARMV5TL_INSTR_MRS;        //Move status register to register instructions
typedef struct tagARMV5TL_INSTR_MRCMCR      ARMV5TL_INSTR_MRCMCR;     //Move register to coprocessor or coprocessor to register instructions

typedef struct tagARMV5TL_FLAGS             ARMV5TL_FLAGS;
typedef struct tagARMV5TL_REGS              ARMV5TL_REGS;
typedef struct tagARMV5TL_CORE              ARMV5TL_CORE, *PARMV5TL_CORE;

typedef union tagARMV5TL_STATUS             ARMV5TL_STATUS, *PARMV5TL_STATUS;
typedef union tagARMV5TL_ARM_INSTRUCTION    ARMV5TL_ARM_INSTRUCTION;
typedef union tagARMV5TL_MEMORY             ARMV5TL_MEMORY;


typedef void *(*PERIPHERALCHECK)(PARMV5TL_CORE core, u_int32_t address, u_int32_t mode);

//----------------------------------------------------------------------------------------------------------------------------------

struct tagARMV5TL_ADDRESS_MAP
{
  u_int32_t    start;
  u_int32_t    end;
  PERIPHERALCHECK function;
};

//----------------------------------------------------------------------------------------------------------------------------------

struct tagARMV5TL_INSTR_BASE
{
  u_int32_t data:12;      //Addressing data
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t s:1;          //Update status bit
  u_int32_t opcode:4;     //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_MUL
{
  u_int32_t rm:4;         //Register
  u_int32_t nu:4;         //Fixed value
  u_int32_t rs:4;         //Register
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t opcode:4;     //Opcode for type of multiply
  u_int32_t type:4;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_ELS
{
  u_int32_t rm:4;         //Register
  u_int32_t nu1:1;        //Always one
  u_int32_t opcode:2;     //Opcode
  u_int32_t nu2:1;        //Always one
  u_int32_t rs:4;         //Register
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //
  u_int32_t w:1;          //
  u_int32_t b:1;          //
  u_int32_t u:1;          //
  u_int32_t p:1;          //
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_LSI
{
  u_int32_t of:12;        //Offset
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //For offset addressing this is the write back to base indicator.
  u_int32_t b:1;          //Unsigned byte mode
  u_int32_t u:1;          //Offset use mode 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Pre indexed addressing. Combined with W bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_LSR
{
  u_int32_t rm:4;        //Offset
  u_int32_t nu:1;         //Not used
  u_int32_t sm:2;         //Shift mode
  u_int32_t sa:5;         //Shift amount
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //For offset addressing this is the write back to base indicator.
  u_int32_t b:1;          //Unsigned byte mode
  u_int32_t u:1;          //Offset use mode 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Pre indexed addressing. Combined with W bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_LSRN
{
  u_int32_t rm:4;         //Register m
  u_int32_t ns:8;         //No scaling when zero
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //For offset addressing this is the write back to base indicator.
  u_int32_t b:1;          //Unsigned byte mode
  u_int32_t u:1;          //Offset use mode 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Pre indexed addressing. Combined with W bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_LSX
{
  u_int32_t rm:4;         //Register m
  u_int32_t sbo2:1;       //Should be one
  u_int32_t op1:2;        //Extra opcode
  u_int32_t sbo1:1;       //Should be one
  u_int32_t rs:4;         //Register s
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Register n
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //For offset addressing this is the write back to base indicator.
  u_int32_t i:1;          //Immediate offset / index or register offset / index
  u_int32_t u:1;          //Offset use mode 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Pre indexed addressing. Combined with W bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_DPSI
{
  u_int32_t rm:4;         //Register
  u_int32_t t1:1;         //Shift type
  u_int32_t sm:2;         //Shift mode
  u_int32_t sa:5;         //Shift amount
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t opcode:4;     //Opcode for type of multiply
  u_int32_t type:4;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_DPSR
{
  u_int32_t rm:4;         //Register
  u_int32_t t1:1;         //Shift type
  u_int32_t sm:2;         //Shift mode
  u_int32_t nu:1;         //Always 0
  u_int32_t rs:4;         //Shift amount register
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t opcode:4;     //Opcode for type of data processing
  u_int32_t type:4;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_DPI
{
  u_int32_t im:8;         //Immediate value
  u_int32_t ri:4;         //Rotate immediate
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t opcode:4;     //Opcode for type of data processing
  u_int32_t type:4;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_MSRI
{
  u_int32_t im:8;         //Immediate value
  u_int32_t ri:4;         //Rotate immediate
  u_int32_t sbo:4;        //Should be one
  u_int32_t c:1;          //Control field mask
  u_int32_t x:1;          //Extension field mask
  u_int32_t s:1;          //Status field mask
  u_int32_t f:1;          //Flags field mask
  u_int32_t nu1:2;        //Not used after decoding
  u_int32_t r:1;          //Target register select 0: cpsr. 1: spsr.
  u_int32_t nu2:5;        //Not used after decoding
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_MSRR
{
  u_int32_t rm:4;         //Register holding the data
  u_int32_t sbz:8;        //Should be zero
  u_int32_t sbo:4;        //Should be one
  u_int32_t c:1;          //Control field mask
  u_int32_t x:1;          //Extension field mask
  u_int32_t s:1;          //Status field mask
  u_int32_t f:1;          //Flags field mask
  u_int32_t nu1:1;        //Not used after decoding
  u_int32_t d:1;          //Move direction bit
  u_int32_t r:1;          //Target register select 0: cpsr. 1: spsr.
  u_int32_t nu2:5;        //Not used after decoding
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_MRS
{
  u_int32_t sbz:12;       //Should be zero
  u_int32_t rd:4;         //Destination register
  u_int32_t sbo:4;        //Should be one
  u_int32_t nu1:2;        //Not used after decoding
  u_int32_t r:1;          //Source register select 0: cpsr. 1: spsr.
  u_int32_t nu2:5;        //Not used after decoding
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_MRCMCR
{
  u_int32_t crm:4;        //Coprocessor register m
  u_int32_t nu:1;         //Not used after decoding
  u_int32_t op2:3;        //Coprocessor opcode 2
  u_int32_t cpn:4;        //Coprocessor number
  u_int32_t rd:4;         //Destination register
  u_int32_t crn:4;        //Coprocessor register n
  u_int32_t d:1;          //Data direction bit
  u_int32_t op1:3;        //Coprocessor opcode 1
  u_int32_t type:4;       //Type bits
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_MISC0
{
  u_int32_t rm:4;         //Register
  u_int32_t op2:4;        //Opcode 2
  u_int32_t rs:4;         //Multiply register
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t s:1;          //Update status bit
  u_int32_t op1:2;        //Opcode 1
  u_int32_t type:5;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE0
{
  u_int32_t rm:4;         //Register
  u_int32_t it1:1;        //Instruction type
  u_int32_t sm:2;         //Shift mode
  u_int32_t it2:1;        //Instruction type
  u_int32_t rs:4;         //Register
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t s:1;          //Update status bit
  u_int32_t opcode:4;     //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE1
{
  u_int32_t im:8;         //Immediate
  u_int32_t r:4;          //Rotate
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t s:1;          //Update status bit
  u_int32_t opcode:4;     //Actual opcode for some type of instructions
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE2
{
  u_int32_t im:12;        //Immediate data
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //For offset addressing this is the write back to base indicator.
  u_int32_t b:1;          //Unsigned byte mode
  u_int32_t u:1;          //Offset use mode 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Pre indexed addressing. Combined with W bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE3
{
  u_int32_t rm:4;         //Register
  u_int32_t it1:1;        //Instruction type
  u_int32_t sm:2;         //Shift mode
  u_int32_t sa:5;         //Shift amount
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //For offset addressing this is the write back to base indicator.
  u_int32_t b:1;          //Unsigned byte mode
  u_int32_t u:1;          //Offset use mode 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Pre indexed addressing. Combined with W bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE4
{
  u_int32_t r0:1;         //Include r0
  u_int32_t r1:1;         //Include r1
  u_int32_t r2:1;         //Include r2
  u_int32_t r3:1;         //Include r3
  u_int32_t r4:1;         //Include r4
  u_int32_t r5:1;         //Include r5
  u_int32_t r6:1;         //Include r6
  u_int32_t r7:1;         //Include r7
  u_int32_t r8:1;         //Include r8
  u_int32_t r9:1;         //Include r9
  u_int32_t r10:1;        //Include r10
  u_int32_t r11:1;        //Include r11
  u_int32_t r12:1;        //Include r12
  u_int32_t r13:1;        //Include r13
  u_int32_t r14:1;        //Include r14
  u_int32_t r15:1;        //Include r15
  u_int32_t rn:4;         //Register holding the base address
  u_int32_t l:1;          //Load or store. 1: Load. 0: Store.
  u_int32_t w:1;          //Update base register after transfer
  u_int32_t s:1;          //Restore cpsr from spsr when r15 included
  u_int32_t u:1;          //Direction. 1: Add to base. 0: Subtract from base
  u_int32_t p:1;          //Range base included or not
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE5
{
  u_int32_t offset:24;    //Signed offset
  u_int32_t l:1;          //Update link register
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE6
{
  u_int32_t of:8;         //Offset
  u_int32_t cp:4;         //Coprocessor number
  u_int32_t crd:4;        //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //
  u_int32_t w:1;          //
  u_int32_t n:1;          //
  u_int32_t u:1;          //
  u_int32_t p:1;          //
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_INSTR_TYPE7
{
  u_int32_t rm:4;         //Register
  u_int32_t it1:1;        //Type of instruction bit
  u_int32_t sm:2;         //Shift mode
  u_int32_t sa:5;         //Shift amount
  u_int32_t rd:4;         //Destination register
  u_int32_t rn:4;         //Second operand register
  u_int32_t l:1;          //
  u_int32_t w:1;          //
  u_int32_t b:1;          //
  u_int32_t u:1;          //
  u_int32_t it2:1;        //Type of instruction bit
  u_int32_t type:3;       //Type of instructions
  u_int32_t cond:4;       //Condition bits
};

struct tagARMV5TL_FLAGS
{
  u_int32_t M:5;         //Mode bits
  u_int32_t T:1;         //Thumb execution state flag
  u_int32_t F:1;         //Fast Interrupt disable flag
  u_int32_t I:1;         //Interrupt disable flag
  u_int32_t R1:8;        //Reserved bits
  u_int32_t GE:4;        //Greater then or equal flags
  u_int32_t R2:4;        //Reserved bits
  u_int32_t J:1;         //Jazelle execution state flag
  u_int32_t R3:2;        //Reserved bits
  u_int32_t Q:1;         //DSP overflow / saturation flag
  u_int32_t V:1;         //Overflow flag
  u_int32_t C:1;         //Carry flag
  u_int32_t Z:1;         //Zero flag
  u_int32_t N:1;         //Negative flag
};

union tagARMV5TL_STATUS
{
  u_int32_t     word;            //Word register
  ARMV5TL_FLAGS flags;           //Bit flags
};                                        

union tagARMV5TL_ARM_INSTRUCTION
{
  u_int32_t                instr;      //Instruction register
  ARMV5TL_INSTR_BASE       base;       //Base for instruction decoding
  ARMV5TL_INSTR_MISC0      misc0;      //Miscellaneous instructions
  ARMV5TL_INSTR_TYPE0      type0;      //For type 0 instruction decoding
  ARMV5TL_INSTR_TYPE1      type1;      //For type 1 instruction decoding
  ARMV5TL_INSTR_TYPE2      type2;      //For type 2 instruction decoding
  ARMV5TL_INSTR_TYPE3      type3;      //For type 3 instruction decoding
  ARMV5TL_INSTR_TYPE4      type4;      //For type 4 instruction decoding
  ARMV5TL_INSTR_TYPE5      type5;      //For type 5 instruction decoding
  ARMV5TL_INSTR_TYPE6      type6;      //For type 6 instruction decoding
  ARMV5TL_INSTR_TYPE7      type7;      //For type 7 instruction decoding
  ARMV5TL_INSTR_MUL        mul;        //For multiply instructions
  ARMV5TL_INSTR_ELS        els;        //For extra load and store instructions
  ARMV5TL_INSTR_DPSI       dpsi;       //For data processing immediate shift instructions
  ARMV5TL_INSTR_DPSR       dpsr;       //For data processing register shift instructions
  ARMV5TL_INSTR_DPI        dpi;        //For data processing immediate instructions
  ARMV5TL_INSTR_LSI        lsi;        //For load and store immediate instructions
  ARMV5TL_INSTR_LSR        lsr;        //For load and store register instructions
  ARMV5TL_INSTR_LSRN       lsrn;       //For load and store register no scaling instructions
  ARMV5TL_INSTR_LSX        lsx;        //For load and store register extra instructions
  ARMV5TL_INSTR_MSRI       msri;       //Move immediate to status register instructions
  ARMV5TL_INSTR_MSRR       msrr;       //Move register to status register instructions
  ARMV5TL_INSTR_MRS        mrs;        //Move status register to register instructions
  ARMV5TL_INSTR_MRCMCR     mrcmcr;     //Move register to coprocessor or coprocessor to register instructions
};                                        

union tagARMV5TL_MEMORY
{
  u_int32_t  m_32bit;
  u_int16_t  m_16bit[2];
  u_int8_t   m_8bit[4];
};

//The complete arm register set
struct tagARMV5TL_REGS
{
  u_int32_t r0;
  u_int32_t r1;
  u_int32_t r2;
  u_int32_t r3;
  u_int32_t r4;
  u_int32_t r5;
  u_int32_t r6;
  u_int32_t r7;
  u_int32_t r8[2];
  u_int32_t r9[2];
  u_int32_t r10[2];
  u_int32_t r11[2];
  u_int32_t r12[2];
  u_int32_t r13[6];
  u_int32_t r14[6];
  u_int32_t r15;
  u_int32_t cpsr;
  u_int32_t spsr[5];
};

//The core main struct
struct tagARMV5TL_CORE
{
  u_int32_t                *registers[6][18];         //The ARM core has banked register sets. In different modes some of the registers are not available or are the un_banked user mode ones. Pointers are used to emulate this.
  
  u_int32_t                 current_mode;             //The mode the core is running in.
  u_int32_t                 current_bank;             //The register bank currently in use.
  
  ARMV5TL_ARM_INSTRUCTION   arm_instruction;          //The arm instruction loaded for the current cycle. Only when in arm state
  ARMV5TL_THUMB_INSTRUCTION thumb_instruction;        //The thumb instruction loaded for the current cycle. Only when in thumb state
  
  u_int32_t                 pcincrvalue;              //Value the program counter needs to be incremented with
  
  int                      *program_counter;          //For more direct control a pointer to the program counter here
  ARMV5TL_STATUS           *status;                   //Same for the status word
  
  u_int32_t                 reset;                    //Processor reset flag
  u_int32_t                 irq;                      //Processor irg flag
  u_int32_t                 fiq;                      //Processor fast interrupt flag
  u_int32_t                 undefinedinstruction;     //Flag to signal undefined instruction encountered
  
  u_int32_t                 run;                      //Processor run flag
  
  ARMV5TL_MEMORY            sram1[8192];              //32K core startup memory located at address 0x00000000
  ARMV5TL_MEMORY            sram2[10240];             //40K core static memory located at address 0x00010000
  
  ARMV5TL_MEMORY           *dram;                     //Pointer to the memory in the system

  ARMV5TL_REGS              regs;                     //The actual register bank
  
   FILE                    *TraceFilePointer;         //Null if tracing is disabled
};

//----------------------------------------------------------------------------------------------------------------------------------

//The processor modes
#define ARM_MODE_USER            0x10
#define ARM_MODE_FIQ             0x11
#define ARM_MODE_IRQ             0x12
#define ARM_MODE_SUPERVISOR      0x13
#define ARM_MODE_ABORT           0x17
#define ARM_MODE_UNDEFINED       0x1B
#define ARM_MODE_SYSTEM          0x1F

//The processor register banks
#define ARM_REG_BANK_USER          0
#define ARM_REG_BANK_FIQ           1
#define ARM_REG_BANK_IRQ           2
#define ARM_REG_BANK_SUPERVISOR    3
#define ARM_REG_BANK_ABORT         4
#define ARM_REG_BANK_UNDEFINED     5
#define ARM_REG_BANK_SYSTEM        0


#define ARM_REG_SPSR_IDX          17

//----------------------------------------------------------------------------------------------------------------------------------

#define ARM_COND_EQUAL             0           //Z set
#define ARM_COND_NOT_EQUAL         1           //Z clear
#define ARM_COND_CARRY_SET         2           //Carry set / unsigned higher or same
#define ARM_COND_CARRY_CLEAR       3           //Carry clear / unsigned lower
#define ARM_COND_MINUS             4           //N set
#define ARM_COND_PLUS              5           //N clear
#define ARM_COND_OVERFLOW          6           //V set
#define ARM_COND_NO_OVERFLOW       7           //V clear
#define ARM_COND_HIGHER            8           //C set and Z clear
#define ARM_COND_LOWER_SAME        9           //C clear or Z set
#define ARM_COND_GREATER_EQUAL    10           //N set and V set or N clear and V clear (N == V)
#define ARM_COND_LESS_THAN        11           //N set and V clear or N clear and V set (N != V)
#define ARM_COND_GREATER_THAN     12           //Z clear and (N set and V set or N clear and V clear) (Z == 0; N == V)
#define ARM_COND_LESS_THAN_EQUAL  13           //Z set and (N set and V clear or N clear and V set) (Z == 1; N != V)
#define ARM_COND_ALWAYS           14           //Always execute
#define ARM_COND_SPECIAL          15

//----------------------------------------------------------------------------------------------------------------------------------

#define ARM_OPCODE_AND            0
#define ARM_OPCODE_EOR            1
#define ARM_OPCODE_SUB            2
#define ARM_OPCODE_RSB            3
#define ARM_OPCODE_ADD            4
#define ARM_OPCODE_ADC            5
#define ARM_OPCODE_SBC            6
#define ARM_OPCODE_RSC            7
#define ARM_OPCODE_TST            8
#define ARM_OPCODE_TEQ            9
#define ARM_OPCODE_CMP           10
#define ARM_OPCODE_CMN           11
#define ARM_OPCODE_ORR           12
#define ARM_OPCODE_MOV           13
#define ARM_OPCODE_BIC           14
#define ARM_OPCODE_MVN           15

//----------------------------------------------------------------------------------------------------------------------------------

#define ARM_SHIFT_MODE_LSL        0
#define ARM_SHIFT_MODE_LSR        1
#define ARM_SHIFT_MODE_ASR        2
#define ARM_SHIFT_MODE_ROR        3

//----------------------------------------------------------------------------------------------------------------------------------

#define ARM_FLAGS_UPDATE_CV_NO    0    //Do not update the carry and overflow
#define ARM_FLAGS_UPDATE_CV       1    //For add the carry is the carry
#define ARM_FLAGS_UPDATE_NBV      2    //For subtract the carry is the not borrow
#define ARM_FLAGS_UPDATE_CV_CLR   3    //Clear both flags

//----------------------------------------------------------------------------------------------------------------------------------

#define ARM_MEMORY_MASK          0x0003

#define ARM_MEMORY_WORD          0x0000
#define ARM_MEMORY_SHORT         0x0001
#define ARM_MEMORY_BYTE          0x0002

#define ARM_SIGN_EXTEND          0x0010

//----------------------------------------------------------------------------------------------------------------------------------

#define ARM_USER_MASK             0xF8000000
#define ARM_STATE_MASK            0x01000020
#define ARM_PRIVILEGED_MASK       0x000000DF

//----------------------------------------------------------------------------------------------------------------------------------

int startarmcore(void);
void stoparmcore(void);

void *armcorethread(void *arg);

//----------------------------------------------------------------------------------------------------------------------------------

void ArmV5tlSetup(PARMV5TL_CORE core);

void ArmV5tlCore(PARMV5TL_CORE core);

void *ArmV5tlGetMemoryPointer(PARMV5TL_CORE core, u_int32_t address, u_int32_t mode);

//Memory map functions
void *ArmV5tlSram1(PARMV5TL_CORE core, u_int32_t address, u_int32_t mode);
void *ArmV5tlSram2(PARMV5TL_CORE core, u_int32_t address, u_int32_t mode);

//Undefined instruction
void ArmV5tlUndefinedInstruction(PARMV5TL_CORE core);

//Data processing immediate or register shift instruction handling
void ArmV5tlDPRShift(PARMV5TL_CORE core);

//Data processing immediate instruction handling
void ArmV5tlDPRImmediate(PARMV5TL_CORE core);

//Data processing instruction handling
void ArmV5tlDPR(PARMV5TL_CORE core, u_int32_t vn, u_int32_t vm, u_int32_t c);

//Load and store immediate instruction handling
void ArmV5tlLSImmediate(PARMV5TL_CORE core);

//Load and store register instruction handling
void ArmV5tlLSRegister(PARMV5TL_CORE core);

//Load and store extra immediate instruction handling
void ArmV5tlLSExtraImmediate(PARMV5TL_CORE core);

//Load and store extra register instruction handling
void ArmV5tlLSExtraRegister(PARMV5TL_CORE core);

//Load and store instruction handling
void ArmV5tlLS(PARMV5TL_CORE core, u_int32_t address, u_int32_t mode);

//Load and store multiple instruction handling
void ArmV5tlLSM(PARMV5TL_CORE core);

//Move immediate to status register
void ArmV5tlMSRImmediate(PARMV5TL_CORE core);

//Move register to status register
void ArmV5tlMSRRegister(PARMV5TL_CORE core);

//Move to status register
void ArmV5tlMSR(PARMV5TL_CORE core, u_int32_t data);

//Move status register to register
void ArmV5tlMRS(PARMV5TL_CORE core);

//Move register to coprocessor or coprocessor to register
void ArmV5tlMRCMCR(PARMV5TL_CORE core);

//Handle branch instructions
void ArmV5tlBranch(PARMV5TL_CORE core);

//Handle branch with link and exchange instructions
void ArmV5tlBranchLinkExchange1(PARMV5TL_CORE core);

//Handle branch with link and exchange instructions
void ArmV5tlBranchLinkExchange2(PARMV5TL_CORE core);

//Handle branch with exchange instructions
void ArmV5tlBranchExchangeT(PARMV5TL_CORE core);

//Handle branch with exchange instructions
void ArmV5tlBranchExchangeJ(PARMV5TL_CORE core);

#endif /* ARMV5TL_H */


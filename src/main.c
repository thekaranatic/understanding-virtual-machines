// The following program follows LC3 Architecure: 

#include <stdio.h>
#include <stdint.h>

/* MEMORY */

// Starting with simulating the essential hardware components of the machine

// LC-3 has 65536 memory locations (max addressable location by 16-bit u_int i.e. 2^16)
// Each of which stores a 16-bit value, storing a total of 128 KB
// This memory is stored in an array

#define MEMORY_MAX (1 << 16)    // 2^16 = 65536
uint16_t memory[MEMORY_MAX];    // 65536 locations


/* REGISTERS */

// Register - A slot for storing a single value on the CPU

// LC-3 has total 10 registers (16 bits each)
// 8 General Purpose Registers (R0 - R7)
// 1 Program Counter (PC)
// 1 Condition Flag (COND)

enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,    // Progam Counter
    R_COND,
    R_COUNT
};

// These registers are stored in an array
uint16_t reg[R_COUNT];


/* INSTRUCTION SET */

// Instruction - command which tells the CPU to do some fundamental task, such as add two numbers
// Instructions have:
//      - Opcode: Kind of task to perform
//      - Params: Inputs to the task being performed

// Each opcode represents one task that the CPU "knows" how to do
// There are 16 opcodes in LC-3
// Each instruction in 16-bits long, with the left 4 bits storing the opcode, 
// and rest of them for parameters

enum
{
    OP_BR = 0,  // branch
    OP_ADD,     // add
    OP_LD,      // load
    OP_ST,      // store
    OP_JSR,     // jump register
    OP_AND,     // bitwise and   
    OP_LDR,     // load register   
    OP_STR,     // store register   
    OP_RTI,     // unused
    OP_NOT,     // bitwise not 
    OP_LDI,     // load indirect
    OP_STI,     // store indirect
    OP_JMP,     // jump
    OP_RES,     // reserved (unused)
    OP_LEA,     // load effective address 
    OP_TRAP     // execute trap
};

/* CONDITION FLAGS */

// The R_COND register stores condition flags which provide information
// about the most recently executed calculation. 

// LC-3 arch only uses 3 condition flags which indicate the sign of the 
// previous calculation

enum {
    FL_POS = 1 << 0,    // POSITIVE - 1
    FL_ZRO = 1 << 1,    // ZERO     - 2
    FL_NEG = 1 << 2,    // NEGATIVE - 4
};

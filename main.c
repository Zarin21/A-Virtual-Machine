#include <stdio.h>
#include <stdlib.h>

#define MEMORY_MAX (1 << 16) // 65,536 memory locations; maximum that is addressed by a 16-bit unsigned integer (2^16)

__UINT16_TYPE__ memory[MEMORY_MAX]; // 65536 locations

// Registers
enum
{
    /* General - Purpose Register (8) */
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, // Program counter, holds the memory address of the next intruction to be exected by the CPU
    R_COND, // Condition register, may store status flags or results of previous operations
    R_COUNT // Helper constant, total number of register
};

__UINT16_TYPE__ reg[R_COUNT]; // Registers stored

// Opcodes
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

// Condition Flags
enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};


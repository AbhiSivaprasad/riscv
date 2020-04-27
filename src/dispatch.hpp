#ifndef __DISPATCH_HPP__
#define __DISPATCH_HPP__

#include "cpustate.hpp"

// OPCODES
#define OP_BRANCH (0b1100011)
#define OP_JALR   (0b1100111)
#define OP_JAL    (0b1101111)
#define OP_LUI    (0b0110111)
#define OP_AUIPC  (0b0010111)
#define OP_COMPI  (0b0010011)
#define OP_COMP   (0b0110011)
#define OP_LOAD   (0b0000011)
#define OP_STORE  (0b0100011)
#define OP_FENCE  (0b0001111)
#define OP_ECALL  (0b1110011)
#define OP_AMO    (0b0101111)

// COMP
#define FUNCT3_ADD_SUB (0) // add, sub
#define FUNCT3_SLL     (1)
#define FUNCT3_SLT     (2)
#define FUNCT3_SLTU    (3)
#define FUNCT3_XOR     (4)
#define FUNCT3_SRL_SRA (5) // srl, sra
#define FUNCT3_OR      (6)
#define FUNCT3_AND     (7)
#define FUNCT7_SRL     (0b0000000)
#define FUNCT7_SRA     (0b0100000)
#define FUNCT7_ADD     (0b0000000)
#define FUNCT7_SUB     (0b0100000)

// LOAD
#define FUNCT3_LB  (0)
#define FUNCT3_LH  (1)
#define FUNCT3_LW  (2)
#define FUNCT3_LBU (4)
#define FUNCT3_LHU (5)

// STORE
#define FUNCT3_SB (0)
#define FUNCT3_SH (1)
#define FUNCT3_SW (2)

// BRANCH
#define FUNCT3_BEQ  (0)
#define FUNCT3_BNE  (1)
#define FUNCT3_BLT  (4)
#define FUNCT3_BGE  (5)
#define FUNCT3_BLTU (6)
#define FUNCT3_BGEU (7)

// FENCE
#define FUNCT3_FENCE  (0)
#define FUNCT3_FENCEI (1)

// ECALL
#define FUNCT12_ECALL  (0)
#define FUNCT12_EBREAK (1)

// AMO
#define FUNCT3_AMO     (2)
#define FUNCT5_LR      (0b00010)
#define FUNCT5_SC      (0b00011)
#define FUNCT5_AMOSWAP (0b00001)
#define FUNCT5_AMOADD  (0b00000)
#define FUNCT5_AMOXOR  (0b00100)
#define FUNCT5_AMOAND  (0b01100)
#define FUNCT5_AMOOR   (0b01000)
#define FUNCT5_AMOMIN  (0b10000)
#define FUNCT5_AMOMAX  (0b10100)
#define FUNCT5_AMOMINU (0b11000)
#define FUNCT5_AMOMAXU (0b11100)

void dispatch(uint32_t instruction, CPUState& state);

#endif

#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include <cstdint>

#define WORD_SIZE 32

/* UNIQUE OPCODES */
#define OP_BRANCH 0x63  // 1100011
#define OP_JALR   0x67  // 1100111
#define OP_JAL    0x6F  // 1101111
#define OP_LUI    0x37  // 0110111
#define OP_AUIPC  0x17  // 0010111
#define OP_COMPI  0x13  // 0010011
#define OP_COMP   0x33  // 0110011
#define OP_LOAD   0x3   // 0000011
#define OP_STORE  0x23  // 0100011
#define OP_FENCE  0xF   // 0001111

/* COMP */
#define FUNCT3_ADSB 0<<12 // add, sub
#define FUNCT3_ADD  0<<12
#define FUNCT3_SLL  1<<12
#define FUNCT3_SLT  2<<12
#define FUNCT3_SLTU 3<<12
#define FUNCT3_XOR  4<<12
#define FUNCT3_SRLA 5<<12 // srl, sra
#define FUNCT3_OR   6<<12
#define FUNCT3_AND  7<<12

/* LOAD */
#define FUNCT3_LB   0<<12
#define FUNCT3_LH   1<<12
#define FUNCT3_LW   2<<12
#define FUNCT3_LBU  4<<12
#define FUNCT3_LHU  5<<12

/* STORE */
#define FUNCT3_SB   0<<12
#define FUNCT3_SH   1<<12
#define FUNCT3_SW   2<<12

/* BRANCH */
#define FUNCT3_BEQ  0<<12
#define FUNCT3_BNE  1<<12
#define FUNCT3_BLT  4<<12
#define FUNCT3_BGE  5<<12
#define FUNCT3_BLTU 6<<12
#define FUNCT3_BGEU 7<<12

/* FENCE */
#define FUNCT3_FENCE  0<<12
#define FUNCT3_FENCEI 1<<12

/* FUNCT7 */
#define FUNCT7_SRL  0<<30 // 0000000
#define FUNCT7_SRA  1<<30 // 0100000
#define FUNCT7_ADD  0<<30 // 0000000
#define FUNCT7_SUB  1<<30 // 0100000
 
struct RInstruction {
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;

    static RInstruction parseR(uint32_t instruction);
};

struct IInstruction {
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint32_t imm;

    static IInstruction parseI(uint32_t instruction);
};

struct SInstruction {
    uint8_t opcode;
    uint32_t imm;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;

    static SInstruction parseS(uint32_t instruction);
    static SInstruction parseB(uint32_t instruction);
};

struct UInstruction {
    uint8_t opcode;
    uint8_t rd;
    uint32_t imm;

    static UInstruction parseU(uint32_t instruction);
    static UInstruction parseJ(uint32_t instruction);
};

uint8_t matchFunct3(uint32_t instruction, uint32_t funct3Mask);
uint8_t matchFunct7(uint32_t instruction, uint32_t funct7Mask);
uint8_t matchOpcode(uint32_t instruction, uint32_t opcodeMask);

#endif

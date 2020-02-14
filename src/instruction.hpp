#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include <cstdint>

/* UNIQUE OPCODES */
#define OP_BRANCH 0x63  // 1100011
#define OP_JALR 0x67    // 1100111
#define OP_JAL 0x6F     // 1101111
#define OP_LUI 0x37     // 0110111
#define OP_AUIPC 0x17   // 0010111
#define OP_COMPI 0x13   // 0010011
#define OP_COMP 0x33    // 0110011
#define OP_LOAD 0x3     // 0000011
#define OP_STORE 0x23   // 0100011
#define OP_FENCE 0xF    // 0001111

#define FUNCT3_ADD  0<<12   
#define FUNCT3_SUB  0<<12
#define FUNCT3_SLL  1<<12
#define FUNCT3_SLT  2<<12
#define FUNCT3_SLTU 3<<12
#define FUNCT3_XOR  4<<12
#define FUNCT3_SRL  5<<12
#define FUNCT3_SRA  5<<12
#define FUNCT3_OR   6<<12
#define FUNCT3_AND  7<<12

#define FUNCT7_SRA  1<<30 // 0100000
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

#endif

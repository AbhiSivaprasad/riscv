#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include <cstdint>

/* OPCODES */
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

/* COMP */
#define FUNCT3_ADD_SUB (0) // add, sub
#define FUNCT3_SLL  (1)
#define FUNCT3_SLT  (2)
#define FUNCT3_SLTU (3)
#define FUNCT3_XOR  (4)
#define FUNCT3_SRL_SRA (5) // srl, sra
#define FUNCT3_OR   (6)
#define FUNCT3_AND  (7)

/* LOAD */
#define FUNCT3_LB   (0)
#define FUNCT3_LH   (1)
#define FUNCT3_LW   (2)
#define FUNCT3_LBU  (4)
#define FUNCT3_LHU  (5)

/* STORE */
#define FUNCT3_SB   (0)
#define FUNCT3_SH   (1)
#define FUNCT3_SW   (2)

/* BRANCH */
#define FUNCT3_BEQ  (0)
#define FUNCT3_BNE  (1)
#define FUNCT3_BLT  (4)
#define FUNCT3_BGE  (5)
#define FUNCT3_BLTU (6)
#define FUNCT3_BGEU (7)

/* FENCE */
#define FUNCT3_FENCE  (0)
#define FUNCT3_FENCEI (1)

/* FUNCT7 */
#define FUNCT7_SRL (0) // 0000000
#define FUNCT7_SRA (1<<5) // 0100000
#define FUNCT7_ADD (0) // 0000000
#define FUNCT7_SUB (1<<5) // 0100000

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

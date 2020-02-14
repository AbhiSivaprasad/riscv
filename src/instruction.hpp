#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include <cstdint>

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

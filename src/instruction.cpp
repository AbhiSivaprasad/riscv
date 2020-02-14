#include "instruction.hpp"

uint32_t get_bits(uint32_t x, int i, int j) {
    uint32_t mask = ~0 ^ (~0 << (j - i));
    return (x >> i) & mask;
}

// TODO: sign extend immediates

RInstruction RInstruction::parseR(uint32_t instruction) {
    RInstruction r_instruction;
    r_instruction.opcode = get_bits(instruction, 0, 7);
    r_instruction.rd = get_bits(instruction, 7, 12);
    r_instruction.funct3 = get_bits(instruction, 12, 15);
    r_instruction.rs1 = get_bits(instruction, 15, 20);
    r_instruction.rs2 = get_bits(instruction, 20, 25);
    r_instruction.funct7 = get_bits(instruction, 25, 32);
}

IInstruction IInstruction::parseI(uint32_t instruction) {
    IInstruction i_instruction;
    i_instruction.opcode = get_bits(instruction, 0, 7);
    i_instruction.rd = get_bits(instruction, 7, 12);
    i_instruction.funct3 = get_bits(instruction, 12, 15);
    i_instruction.rs1 = get_bits(instruction, 15, 20);
    i_instruction.imm = get_bits(instruction, 20, 32);
}

SInstruction SInstruction::parseS(uint32_t instruction) {
    SInstruction s_instruction;
    s_instruction.opcode = get_bits(instruction, 0, 7);
    s_instruction.funct3 = get_bits(instruction, 12, 15);
    s_instruction.rs1 = get_bits(instruction, 15, 20);
    s_instruction.rs2 = get_bits(instruction, 20, 25);
    s_instruction.imm = get_bits(instruction, 7, 12)
        & (get_bits(instruction, 25, 32) << 5);
}

SInstruction SInstruction::parseB(uint32_t instruction) {
    SInstruction s_instruction;
    s_instruction.opcode = get_bits(instruction, 0, 7);
    s_instruction.funct3 = get_bits(instruction, 12, 15);
    s_instruction.rs1 = get_bits(instruction, 15, 20);
    s_instruction.rs2 = get_bits(instruction, 20, 25);
    s_instruction.imm = (BIT_7(instruction) << 11)
        & (get_bits(instruction, 8, 12) << 1)
        & (get_bits(instruction, 25, 31) << 5)
        & (get_bits(instruction, 31, 32) << 12);
}

UInstruction UInstruction::parseU(uint32_t instruction) {
    UInstruction u_instruction;
    u_instruction.opcode = get_bits(instruction, 0, 7);
    u_instruction.rd = get_bits(instruction, 7, 12);
    u_instruction.imm = get_bits(instruction, 12, 32) << 12;
}

UInstruction UInstruction::parseJ(uint32_t instruction) {
    UInstruction u_instruction;
    u_instruction.opcode = get_bits(instruction, 0, 7);
    u_instruction.rd = get_bits(instruction, 7, 12);
    u_instruction.imm = (get_bits(instruction, 12, 20) << 12)
        & (get_bits(instruction, 20, 21) << 11)
        & (get_bits(instruction, 21, 31) << 1)
        & (get_bits(instruction, 31, 32) << 20);
}

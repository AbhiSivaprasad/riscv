#include "ops.hpp"

#include "util.hpp"

void rv32i_lui(uint32_t instruction, CPUState& state) {
    UInstruction i = UInstruction::parseU(instruction);
    state.set_x(i.rd, i.imm);
}

void rv32i_auipc(uint32_t instruction, CPUState& state) {
    UInstruction i = UInstruction::parseU(instruction);
    state.set_x(i.rd, state.get_pc() + i.imm);
}

void rv32i_jal(uint32_t instruction, CPUState& state) {
    UInstruction i = UInstruction::parseJ(instruction);
    state.set_x(i.rd, state.get_pc() + 4);
    state.set_pc(state.get_pc() + i.imm);
}

void rv32i_jalr(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t target = i.imm + state.get_x(i.rs1);
    target &= ~0b1U;
    state.set_x(i.rd, state.get_pc() + 4);
    state.set_pc(target);
}

void rv32i_beq(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseB(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    if (r1 == r2) {
        state.set_pc(state.get_pc() + i.imm);
    }
}

void rv32i_bne(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseB(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    if (r1 != r2) {
        state.set_pc(state.get_pc() + i.imm);
    }
}

void rv32i_blt(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseB(instruction);
    int32_t r1 = state.get_x(i.rs1);
    int32_t r2 = state.get_x(i.rs2);
    if (r1 < r2) {
        state.set_pc(state.get_pc() + i.imm);
    }
}

void rv32i_bge(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseB(instruction);
    int32_t r1 = state.get_x(i.rs1);
    int32_t r2 = state.get_x(i.rs2);
    if (r1 >= r2) {
        state.set_pc(state.get_pc() + i.imm);
    }
}

void rv32i_bltu(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseB(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    if (r1 < r2) {
        state.set_pc(state.get_pc() + i.imm);
    }
}

void rv32i_bgeu(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseB(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    if (r1 >= r2) {
        state.set_pc(state.get_pc() + i.imm);
    }
}

void rv32i_lb(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint32_t val = sign_extend(state.get_mem8(addr), 7);
    state.set_x(i.rd, val);
}

void rv32i_lh(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint32_t val = sign_extend(state.get_mem16(addr), 15);
    state.set_x(i.rd, val);
}

void rv32i_lw(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint32_t val = state.get_mem32(addr);
    state.set_x(i.rd, val);
}

void rv32i_lbu(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint32_t val = state.get_mem8(addr);
    state.set_x(i.rd, val);
}

void rv32i_lhu(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint32_t val = state.get_mem16(addr);
    state.set_x(i.rd, val);
}

void rv32i_sb(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseS(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint8_t val = state.get_x(i.rs2);
    state.set_mem32(addr, val);
}

void rv32i_sh(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseS(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint16_t val = state.get_x(i.rs2);
    state.set_mem32(addr, val);
}

void rv32i_sw(uint32_t instruction, CPUState& state) {
    SInstruction i = SInstruction::parseS(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    uint32_t val = state.get_x(i.rs2);
    state.set_mem32(addr, val);
}

void rv32i_addi(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t addr = state.get_x(i.rs1) + i.imm;
    state.set_x(i.rd, addr);
}

void rv32i_slti(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    int32_t r1 = state.get_x(i.rs1);
    int32_t r2 = i.imm;
    state.set_x(i.rd, r1 < r2);
}

void rv32i_sltiu(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t imm = i.imm;
    state.set_x(i.rd, r1 < imm);
}

void rv32i_xori(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t imm = i.imm;
    state.set_x(i.rd, r1 ^ imm);
}

void rv32i_ori(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t imm = i.imm;
    state.set_x(i.rd, r1 | imm);
}

void rv32i_andi(uint32_t instruction, CPUState& state) {
    IInstruction i = IInstruction::parseI(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t imm = i.imm;
    state.set_x(i.rd, r1 & imm);
}

void rv32i_slli(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t imm = i.rs2;
    state.set_x(i.rd, r1 << imm);
}

void rv32i_srli(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t imm = i.rs2;
    state.set_x(i.rd, r1 >> imm);
}

void rv32i_srai(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    int32_t r1 = state.get_x(i.rs1);
    int32_t imm = i.rs2;
    state.set_x(i.rd, r1 >> imm);
}

void rv32i_add(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 + r2);
}

void rv32i_sub(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 - r2);
}

void rv32i_sll(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 << r2);
}

void rv32i_slt(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    int32_t r1 = state.get_x(i.rs1);
    int32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 < r2);
}

void rv32i_sltu(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 < r2);
}

void rv32i_xor(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 ^ r2);
}

void rv32i_srl(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 >> r2);
}

void rv32i_sra(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    int32_t r1 = state.get_x(i.rs1);
    int32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 >> r2);
}

void rv32i_or(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 | r2);
}

void rv32i_and(uint32_t instruction, CPUState& state) {
    RInstruction i = RInstruction::parseR(instruction);
    uint32_t r1 = state.get_x(i.rs1);
    uint32_t r2 = state.get_x(i.rs2);
    state.set_x(i.rd, r1 & r2);
}

void rv32i_fence(uint32_t, CPUState&) {}

void rv32i_fencei(uint32_t, CPUState&) {}

// void rv32i_ecall(IInstruction& instruction, CPUState& state) {}

// void rv32i_ebreak(IInstruction& instruction, CPUState& state) {}

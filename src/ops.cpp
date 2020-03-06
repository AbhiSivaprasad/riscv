#include "ops.hpp"
#include "util.hpp"

// XXX: is signed addition necessary for addrs
// TODO: error checking
void rv32i_lui(UInstruction &instruction, CPUState &state) {
    state.set_x(instruction.rd, instruction.imm);
}

// TODO: error checking
void rv32i_auipc(UInstruction &instruction, CPUState &state) {
    state.set_x(instruction.rd, state.get_pc() + instruction.imm);
}

// TODO: error checking
void rv32i_jal(UInstruction &instruction, CPUState &state) {
    state.set_x(instruction.rd, state.get_pc() + 4);
    state.set_pc(state.get_pc() + instruction.imm);
    // TODO: check for misaligned target
}

// TODO: error checking
void rv32i_jalr(IInstruction &instruction, CPUState &state) {
    uint32_t target = instruction.imm + state.get_x(instruction.rs1);
    target &= ~0b1U;
    state.set_x(instruction.rd, state.get_pc() + 4);
    state.set_pc(target);
    // TODO: check for misaligned target
}

// TODO: error checking
void rv32i_beq(SInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    if (r1 == r2) {
        state.set_pc(state.get_pc() + instruction.imm);
    }
}

// TODO: error checking
void rv32i_bne(SInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    if (r1 != r2) {
        state.set_pc(state.get_pc() + instruction.imm);
    }
}

// TODO: error checking
void rv32i_blt(SInstruction &instruction, CPUState &state) {
    int32_t r1 = state.get_x(instruction.rs1);
    int32_t r2 = state.get_x(instruction.rs2);
    if (r1 < r2) {
        state.set_pc(state.get_pc() + instruction.imm);
    }
}

// TODO: error checking
void rv32i_bge(SInstruction &instruction, CPUState &state) {
    int32_t r1 = state.get_x(instruction.rs1);
    int32_t r2 = state.get_x(instruction.rs2);
    if (r1 >= r2) {
        state.set_pc(state.get_pc() + instruction.imm);
    }
}

// TODO: error checking
void rv32i_bltu(SInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    if (r1 < r2) {
        state.set_pc(state.get_pc() + instruction.imm);
    }
}

// TODO: error checking
void rv32i_bgeu(SInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    if (r1 >= r2) {
        state.set_pc(state.get_pc() + instruction.imm);
    }
}

// TODO: error checking
void rv32i_lb(IInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint32_t val = sign_extend(state.get_mem8(addr), 7);
    state.set_x(instruction.rd, val);
}

// TODO: error checking
void rv32i_lh(IInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint32_t val = sign_extend(state.get_mem16(addr), 15);
    state.set_x(instruction.rd, val);
}

// TODO: error checking
void rv32i_lw(IInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint32_t val = state.get_mem32(addr);
    state.set_x(instruction.rd, val);
}

// TODO: error checking
void rv32i_lbu(IInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint32_t val = state.get_mem8(addr);
    state.set_x(instruction.rd, val);
}

// TODO: error checking
void rv32i_lhu(IInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint32_t val = state.get_mem16(addr);
    state.set_x(instruction.rd, val);
}

// TODO: error checking
void rv32i_sb(SInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint8_t val = state.get_x(instruction.rs2);
    state.set_mem32(addr, val);
}

// TODO: error checking
void rv32i_sh(SInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint16_t val = state.get_x(instruction.rs2);
    state.set_mem32(addr, val);
}

// TODO: error checking
void rv32i_sw(SInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
    uint32_t val = state.get_x(instruction.rs2);
    state.set_mem32(addr, val);
}

void rv32i_addi(IInstruction &instruction, CPUState &state) {
    uint32_t addr = state.get_x(instruction.rs1) + instruction.imm;
	state.set_x(instruction.rd, addr);
}

void rv32i_slti(IInstruction &instruction, CPUState &state) {
    int32_t r1 = state.get_x(instruction.rs1);
    int32_t r2 = instruction.imm;
	state.set_x(instruction.rd, r1 < r2);
}

void rv32i_sltiu(IInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t imm = instruction.imm;
	state.set_x(instruction.rd, r1 < imm);
}

void rv32i_xori(IInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t imm = instruction.imm;
	state.set_x(instruction.rd, r1 ^ imm);
}

void rv32i_ori(IInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t imm = instruction.imm;
	state.set_x(instruction.rd, r1 | imm);
}

void rv32i_andi(IInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t imm = instruction.imm;
	state.set_x(instruction.rd, r1 & imm);
}

void rv32i_slli(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t imm = instruction.rs2;
	state.set_x(instruction.rd, r1 << imm);
}

void rv32i_srli(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t imm = instruction.rs2;
	state.set_x(instruction.rd, r1 >> imm);
}

void rv32i_srai(RInstruction &instruction, CPUState &state) {
    int32_t r1 = state.get_x(instruction.rs1);
    int32_t imm = instruction.rs2;
	state.set_x(instruction.rd, r1 >> imm);
}

void rv32i_add(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
	state.set_x(instruction.rd, r1 + r2);
}

void rv32i_sub(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
	state.set_x(instruction.rd, r1 - r2);
}

void rv32i_sll(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
	state.set_x(instruction.rd, r1 << r2);
}

void rv32i_slt(RInstruction &instruction, CPUState &state) {
    int32_t r1 = state.get_x(instruction.rs1);
    int32_t r2 = state.get_x(instruction.rs2);
	state.set_x(instruction.rd, r1 < r2);
}

void rv32i_sltu(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    state.set_x(instruction.rd, r1 < r2);
}

void rv32i_xor(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    state.set_x(instruction.rd, r1 ^ r2);
}

void rv32i_srl(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    state.set_x(instruction.rd, r1 >> r2);
}

void rv32i_sra(RInstruction &instruction, CPUState &state) {
    int32_t r1 = state.get_x(instruction.rs1);
    int32_t r2 = state.get_x(instruction.rs2);
    state.set_x(instruction.rd, r1 >> r2);
}

void rv32i_or(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
	state.set_x(instruction.rd, r1 | r2);
}

void rv32i_and(RInstruction &instruction, CPUState &state) {
    uint32_t r1 = state.get_x(instruction.rs1);
    uint32_t r2 = state.get_x(instruction.rs2);
    state.set_x(instruction.rd, r1 & r2);
}

void rv32i_fence(IInstruction &, CPUState &) {}

void rv32i_fencei(IInstruction &, CPUState &) {}

// void rv32i_ecall(IInstruction &instruction, CPUState &state) {}

// void rv32i_ebreak(IInstruction &instruction, CPUState &state) {}

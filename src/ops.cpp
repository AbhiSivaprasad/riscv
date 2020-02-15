#include "ops.hpp"
#include "cpustate.hpp"

void rv32i_lui(UInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, instruction.imm);
}

void rv32i_auipc(UInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, instruction.imm + state.get_pc());
}

void rv32i_jal(UInstruction &instruction, CPUState &state) {
	state.set_pc(state.get_pc() + instruction.imm);
	state.set_x(instruction.rd, state.get_pc() + WORD_SIZE);
}

void rv32i_jalr(IInstruction &instruction, CPUState &state) {
	uint32_t unaligned_jmp_addr = state.get_x(instruction.rs1) + instruction.imm;
	uint32_t aligned_jmp_addr = unaligned_jmp_addr & ~1U;
	
	state.set_pc(aligned_jmp_addr);
	state.set_x(instruction.rd, state.get_pc() + WORD_SIZE);
}

void rv32i_beq(SInstruction &instruction, CPUState &state) {
	if (state.get_x(instruction.rs1) == state.get_x(instruction.rs2))
		state.set_pc(state.get_pc() + instruction.imm);
}

void rv32i_bne(SInstruction &instruction, CPUState &state) {
	if (state.get_x(instruction.rs1) != state.get_x(instruction.rs2))
		state.set_pc(state.get_pc() + instruction.imm);
}

void rv32i_blt(SInstruction &instruction, CPUState &state) {
	if ((int32_t) state.get_x(instruction.rs1) < (int32_t) state.get_x(instruction.rs2))
		state.set_pc(state.get_pc() + instruction.imm);
}

void rv32i_bge(SInstruction &instruction, CPUState &state) {
	if ((int32_t) state.get_x(instruction.rs1) >= (int32_t) state.get_x(instruction.rs2))
		state.set_pc(state.get_pc() + instruction.imm);
}

void rv32i_bltu(SInstruction &instruction, CPUState &state) {
	if (state.get_x(instruction.rs1) < state.get_x(instruction.rs2))
		state.set_pc(state.get_pc() + instruction.imm);
}

void rv32i_bgeu(SInstruction &instruction, CPUState &state) {
	if (state.get_x(instruction.rs1) >= state.get_x(instruction.rs2))
		state.set_pc(state.get_pc() + instruction.imm);
}

// void rv32i_lb(IInstruction &instruction, CPUState &state) {}

// void rv32i_lh(IInstruction &instruction, CPUState &state) {}

// void rv32i_lw(IInstruction &instruction, CPUState &state) {}

// void rv32i_lbu(IInstruction &instruction, CPUState &state) {}

// void rv32i_lhu(IInstruction &instruction, CPUState &state) {}

// void rv32i_sb(SInstruction &instruction, CPUState &state) {}

// void rv32i_sh(SInstruction &instruction, CPUState &state) {}

// void rv32i_sw(SInstruction &instruction, CPUState &state) {}

void rv32i_addi(IInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, instruction.rs1 + instruction.imm);
}

void rv32i_slti(IInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, (int32_t)instruction.rs1 < (int32_t)instruction.imm);
}

void rv32i_sltiu(IInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, instruction.rs1 < instruction.imm);
}

void rv32i_xori(IInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) ^ instruction.imm);
}

void rv32i_ori(IInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) | instruction.imm);
}

void rv32i_andi(IInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) & instruction.imm);
}

void rv32i_slli(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) << instruction.rs2);
}

void rv32i_srli(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) >> instruction.rs2);
}

void rv32i_srai(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, (int32_t) state.get_x(instruction.rs1) >> instruction.rs2);
}

void rv32i_add(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) + instruction.rs2);
}

void rv32i_sub(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) - state.get_x(instruction.rs2));
}

void rv32i_sll(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) << state.get_x(instruction.rs2));
}

void rv32i_slt(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, (int32_t) instruction.rs1 < (int32_t) instruction.rs2);
}

void rv32i_sltu(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, instruction.rs1 < instruction.rs2);
}

void rv32i_xor(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) ^ state.get_x(instruction.rs2));
}

void rv32i_srl(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) >> state.get_x(instruction.rs2));
}

void rv32i_sra(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, (int32_t) state.get_x(instruction.rs1) >> state.get_x(instruction.rs2));
}

void rv32i_or(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) | state.get_x(instruction.rs2));
}

void rv32i_and(RInstruction &instruction, CPUState &state) {
	state.set_x(instruction.rd, state.get_x(instruction.rs1) & state.get_x(instruction.rs2));
}

// void rv32i_fence(IInstruction &instruction, CPUState &state) {}

// void rv32i_fence_i(IInstruction &instruction, CPUState &state) {}

// void rv32i_ecall(IInstruction &instruction, CPUState &state) {}

// void rv32i_ebreak(IInstruction &instruction, CPUState &state) {}

#ifndef __OPS_HPP__
#define __OPS_HPP__

#include "cpustate.hpp"
#include "instruction.hpp"

void rv32i_lui(UInstruction &instruction, CPUState &state);
void rv32i_auipc(UInstruction &instruction, CPUState &state);
void rv32i_jal(UInstruction &instruction, CPUState &state);
void rv32i_jalr(IInstruction &instruction, CPUState &state);
void rv32i_beq(SInstruction &instruction, CPUState &state);
void rv32i_bne(SInstruction &instruction, CPUState &state);
void rv32i_blt(SInstruction &instruction, CPUState &state);
void rv32i_bge(SInstruction &instruction, CPUState &state);
void rv32i_bltu(SInstruction &instruction, CPUState &state);
void rv32i_bgeu(SInstruction &instruction, CPUState &state);
void rv32i_lb(IInstruction &instruction, CPUState &state);
void rv32i_lh(IInstruction &instruction, CPUState &state);
void rv32i_lw(IInstruction &instruction, CPUState &state);
void rv32i_lbu(IInstruction &instruction, CPUState &state);
void rv32i_lhu(IInstruction &instruction, CPUState &state);
void rv32i_sb(SInstruction &instruction, CPUState &state);
void rv32i_sh(SInstruction &instruction, CPUState &state);
void rv32i_sw(SInstruction &instruction, CPUState &state);
void rv32i_addi(IInstruction &instruction, CPUState &state);
void rv32i_slti(IInstruction &instruction, CPUState &state);
void rv32i_sltiu(IInstruction &instruction, CPUState &state);
void rv32i_xori(IInstruction &instruction, CPUState &state);
void rv32i_ori(IInstruction &instruction, CPUState &state);
void rv32i_addi(IInstruction &instruction, CPUState &state);
void rv32i_slti(IInstruction &instruction, CPUState &state);
void rv32i_sltiu(IInstruction &instruction, CPUState &state);
void rv32i_xori(IInstruction &instruction, CPUState &state);
void rv32i_ori(IInstruction &instruction, CPUState &state);
void rv32i_and(IInstruction &instruction, CPUState &state);
void rv32i_andi(IInstruction& instruction, CPUState& state);
void rv32i_slli(RInstruction &instruction, CPUState &state);
void rv32i_srli(RInstruction &instruction, CPUState &state);
void rv32i_srai(RInstruction &instruction, CPUState &state);
void rv32i_add(RInstruction &instruction, CPUState &state);
void rv32i_sub(RInstruction &instruction, CPUState &state);
void rv32i_sll(RInstruction &instruction, CPUState &state);
void rv32i_slt(RInstruction &instruction, CPUState &state);
void rv32i_sltu(RInstruction &instruction, CPUState &state);
void rv32i_xor(RInstruction &instruction, CPUState &state);
void rv32i_srl(RInstruction &instruction, CPUState &state);
void rv32i_sra(RInstruction &instruction, CPUState &state);
void rv32i_or(RInstruction &instruction, CPUState &state);
void rv32i_and(RInstruction &instruction, CPUState &state);
void rv32i_fence(IInstruction &instruction, CPUState &state);
void rv32i_fencei(IInstruction &instruction, CPUState &state);
void rv32i_ecall(IInstruction &instruction, CPUState &state);
void rv32i_ebreak(IInstruction &instruction, CPUState &state);

#endif

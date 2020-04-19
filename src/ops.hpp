#ifndef __OPS_HPP__
#define __OPS_HPP__

#include "cpustate.hpp"
#include "instruction.hpp"

void rv32i_lui(uint32_t instruction, CPUState& state);
void rv32i_auipc(uint32_t instruction, CPUState& state);
void rv32i_jal(uint32_t instruction, CPUState& state);
void rv32i_jalr(uint32_t instruction, CPUState& state);
void rv32i_beq(uint32_t instruction, CPUState& state);
void rv32i_bne(uint32_t instruction, CPUState& state);
void rv32i_blt(uint32_t instruction, CPUState& state);
void rv32i_bge(uint32_t instruction, CPUState& state);
void rv32i_bltu(uint32_t instruction, CPUState& state);
void rv32i_bgeu(uint32_t instruction, CPUState& state);
void rv32i_lb(uint32_t instruction, CPUState& state);
void rv32i_lh(uint32_t instruction, CPUState& state);
void rv32i_lw(uint32_t instruction, CPUState& state);
void rv32i_lbu(uint32_t instruction, CPUState& state);
void rv32i_lhu(uint32_t instruction, CPUState& state);
void rv32i_sb(uint32_t instruction, CPUState& state);
void rv32i_sh(uint32_t instruction, CPUState& state);
void rv32i_sw(uint32_t instruction, CPUState& state);
void rv32i_addi(uint32_t instruction, CPUState& state);
void rv32i_slti(uint32_t instruction, CPUState& state);
void rv32i_sltiu(uint32_t instruction, CPUState& state);
void rv32i_xori(uint32_t instruction, CPUState& state);
void rv32i_ori(uint32_t instruction, CPUState& state);
void rv32i_addi(uint32_t instruction, CPUState& state);
void rv32i_slti(uint32_t instruction, CPUState& state);
void rv32i_sltiu(uint32_t instruction, CPUState& state);
void rv32i_xori(uint32_t instruction, CPUState& state);
void rv32i_ori(uint32_t instruction, CPUState& state);
void rv32i_and(uint32_t instruction, CPUState& state);
void rv32i_andi(uint32_t instruction, CPUState& state);
void rv32i_slli(uint32_t instruction, CPUState& state);
void rv32i_srli(uint32_t instruction, CPUState& state);
void rv32i_srai(uint32_t instruction, CPUState& state);
void rv32i_add(uint32_t instruction, CPUState& state);
void rv32i_sub(uint32_t instruction, CPUState& state);
void rv32i_sll(uint32_t instruction, CPUState& state);
void rv32i_slt(uint32_t instruction, CPUState& state);
void rv32i_sltu(uint32_t instruction, CPUState& state);
void rv32i_xor(uint32_t instruction, CPUState& state);
void rv32i_srl(uint32_t instruction, CPUState& state);
void rv32i_sra(uint32_t instruction, CPUState& state);
void rv32i_or(uint32_t instruction, CPUState& state);
void rv32i_and(uint32_t instruction, CPUState& state);
void rv32i_fence(uint32_t instruction, CPUState& state);
void rv32i_fencei(uint32_t instruction, CPUState& state);
void rv32i_ecall(uint32_t instruction, CPUState& state);
void rv32i_ebreak(uint32_t instruction, CPUState& state);

#endif

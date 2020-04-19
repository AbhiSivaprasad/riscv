#include "dispatch.hpp"

#include "ops.hpp"
#include "util.hpp"

bool dispatch(uint32_t instruction, CPUState& state) {
    uint8_t opcode = get_bits(instruction, 0, 7);
    uint8_t funct3 = get_bits(instruction, 12, 15);
    uint8_t funct7 = get_bits(instruction, 25, 32);
    switch (opcode) {
        case OP_AUIPC:
            rv32i_auipc(instruction, state);
            break;
        case OP_BRANCH:
            switch (funct3) {
                case FUNCT3_BEQ:
                    rv32i_beq(instruction, state);
                    break;
                case FUNCT3_BNE:
                    rv32i_bne(instruction, state);
                    break;
                case FUNCT3_BLT:
                    rv32i_blt(instruction, state);
                    break;
                case FUNCT3_BGE:
                    rv32i_bge(instruction, state);
                    break;
                case FUNCT3_BLTU:
                    rv32i_bltu(instruction, state);
                    break;
                case FUNCT3_BGEU:
                    rv32i_bgeu(instruction, state);
                    break;
            }
            break;
        case OP_COMP:
            switch (funct3) {
                case FUNCT3_ADD_SUB:
                    switch (funct7) {
                        case FUNCT7_ADD:
                            rv32i_add(instruction, state);
                            break;
                        case FUNCT7_SUB:
                            rv32i_sub(instruction, state);
                            break;
                    }
                    break;
                case FUNCT3_SLT:
                    rv32i_slt(instruction, state);
                    break;
                case FUNCT3_SLTU:
                    rv32i_sltu(instruction, state);
                    break;
                case FUNCT3_XOR:
                    rv32i_xor(instruction, state);
                    break;
                case FUNCT3_OR:
                    rv32i_or(instruction, state);
                    break;
                case FUNCT3_AND:
                    rv32i_and(instruction, state);
                    break;
                case FUNCT3_SRL_SRA:
                    switch (funct7) {
                        case FUNCT7_SRL:
                            rv32i_srl(instruction, state);
                            break;
                        case FUNCT7_SRA:
                            rv32i_sra(instruction, state);
                            break;
                    }
                    break;
                case FUNCT3_SLL:
                    rv32i_sll(instruction, state);
                    break;
            }
            break;
        case OP_COMPI:
            switch (funct3) {
                case FUNCT3_ADD_SUB:
                    rv32i_addi(instruction, state);
                    break;
                case FUNCT3_SLT:
                    rv32i_slti(instruction, state);
                    break;
                case FUNCT3_SLTU:
                    rv32i_sltiu(instruction, state);
                    break;
                case FUNCT3_XOR:
                    rv32i_xori(instruction, state);
                    break;
                case FUNCT3_OR:
                    rv32i_ori(instruction, state);
                    break;
                case FUNCT3_AND:
                    rv32i_andi(instruction, state);
                    break;
                case FUNCT3_SRL_SRA:
                    switch (funct7) {
                        case FUNCT7_SRL:
                            rv32i_srli(instruction, state);
                            break;
                        case FUNCT7_SRA:
                            rv32i_srai(instruction, state);
                            break;
                    }
                    break;
                case FUNCT3_SLL:
                        rv32i_slli(instruction, state);
                        break;
            }
            break;
        case OP_JAL:
            rv32i_jal(instruction, state);
            return true;
        case OP_JALR:
            rv32i_jalr(instruction, state);
            return true;
        case OP_LOAD:
            switch (funct3) {
                case FUNCT3_LB:
                    rv32i_lb(instruction, state);
                    break;
                case FUNCT3_LH:
                    rv32i_lh(instruction, state);
                    break;
                case FUNCT3_LW:
                    rv32i_lw(instruction, state);
                    break;
                case FUNCT3_LBU:
                    rv32i_lbu(instruction, state);
                    break;
                case FUNCT3_LHU:
                    rv32i_lhu(instruction, state);
                    break;
            }
            break;
        case OP_STORE:
            switch (funct3) {
                case FUNCT3_SB:
                    rv32i_sb(instruction, state);
                    break;
                case FUNCT3_SH:
                    rv32i_sh(instruction, state);
                    break;
                case FUNCT3_SW:
                    rv32i_sw(instruction, state);
                    break;
            }
            break;
        case OP_LUI:
            rv32i_lui(instruction, state);
            break;
        case OP_FENCE:
            switch (funct3) {
                case FUNCT3_FENCE:
                    rv32i_fence(instruction, state);
                    break;
                case FUNCT3_FENCEI:
                    rv32i_fencei(instruction, state);
                    break;
            }
            break;
    }
    return false;
}

#include "dispatch.hpp"

#include "ops.hpp"
#include "util.hpp"

// returns true of pc should be incremented after
bool dispatch(uint32_t instruction, CPUState& state) {
    uint8_t opcode = get_bits(instruction, 0, 7);
    uint8_t funct3;
    uint8_t funct7;
    switch (opcode) {
        case OP_AUIPC:
            rv32i_auipc(instruction, state);
            break;
        case OP_BRANCH:
            funct3 = get_bits(instruction, 12, 15);
            switch (funct3) {
                case FUNCT3_BEQ:
                    return !rv32i_beq(instruction, state);
                case FUNCT3_BNE:
                    return !rv32i_bne(instruction, state);
                case FUNCT3_BLT:
                    return !rv32i_blt(instruction, state);
                case FUNCT3_BGE:
                    return !rv32i_bge(instruction, state);
                case FUNCT3_BLTU:
                    return !rv32i_bltu(instruction, state);
                case FUNCT3_BGEU:
                    return !rv32i_bgeu(instruction, state);
            }
            break;
        case OP_COMP:
            funct3 = get_bits(instruction, 12, 15);
            switch (funct3) {
                case FUNCT3_ADD_SUB:
                    funct7 = get_bits(instruction, 25, 32);
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
                    funct7 = get_bits(instruction, 25, 32);
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
            funct3 = get_bits(instruction, 12, 15);
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
                    funct7 = get_bits(instruction, 25, 32);
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
            return false;
        case OP_JALR:
            rv32i_jalr(instruction, state);
            return false;
        case OP_LOAD:
            funct3 = get_bits(instruction, 12, 15);
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
            funct3 = get_bits(instruction, 12, 15);
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
            funct3 = get_bits(instruction, 12, 15);
            switch (funct3) {
                case FUNCT3_FENCE:
                    rv32i_fence(instruction, state);
                    break;
                case FUNCT3_FENCEI:
                    rv32i_fencei(instruction, state);
                    break;
            }
            break;
        case OP_AMO:
            funct3 = get_bits(instruction, 12, 15);
            switch (funct3) {
                case FUNCT3_AMO:
                    uint8_t funct5 = get_bits(instruction, 27, 32);
                    switch (funct5) {
                        case FUNCT5_LR:
                            rv32a_lr(instruction, state);
                            break;
                        case FUNCT5_SC:
                            rv32a_sc(instruction, state);
                            break;
                        case FUNCT5_AMOSWAP:
                            rv32a_amoswap(instruction, state);
                            break;
                        case FUNCT5_AMOADD:
                            rv32a_amoadd(instruction, state);
                            break;
                        case FUNCT5_AMOXOR:
                            rv32a_amoxor(instruction, state);
                            break;
                        case FUNCT5_AMOAND:
                            rv32a_amoadd(instruction, state);
                            break;
                        case FUNCT5_AMOOR:
                            rv32a_amoor(instruction, state);
                            break;
                        case FUNCT5_AMOMIN:
                            rv32a_amomin(instruction, state);
                            break;
                        case FUNCT5_AMOMAX:
                            rv32a_amomax(instruction, state);
                            break;
                        case FUNCT5_AMOMINU:
                            rv32a_amominu(instruction, state);
                            break;
                        case FUNCT5_AMOMAXU:
                            rv32a_amomaxu(instruction, state);
                            break;
                    }
                    break;
            }
            break;
        case OP_ECALL:
            switch (get_bits(instruction, 20, 32)) {
                case FUNCT12_ECALL:
                    rv32i_ecall(instruction, state);
                    break;
                case FUNCT12_EBREAK:
                    rv32i_ebreak(instruction, state);
                    break;
            }
            break;
        default:
            throw "unknown opcode";
    }
    return true;
}

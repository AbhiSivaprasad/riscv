#include "cpustate.hpp"
#include "instruction.hpp"
#include "ops.hpp"


void dispatch(uint32_t instruction, CPUState state) {
	if (matchOpcode(instruction, OP_AUIPC)) {
		UInstruction inst = UInstruction::parseU(instruction);
		rv32i_auipc(inst, state);
	}
	else if (matchOpcode(instruction, OP_BRANCH)) {
		SInstruction inst = SInstruction::parseB(instruction);
		if (matchFunct3(instruction, FUNCT3_BEQ)) {
			rv32i_beq(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_BNE)) {
			rv32i_bne(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_BLT)) {
			rv32i_blt(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_BGE)) {
			rv32i_bge(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_BLTU)) {
			rv32i_bltu(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_BGEU)) {
			rv32i_bgeu(inst, state);
		}
	}
	else if (matchOpcode(instruction, OP_COMP)) {
		RInstruction inst = RInstruction::parseR(instruction);
		if (matchFunct3(instruction, FUNCT3_ADSB)) {
			if (matchFunct7(instruction, FUNCT7_SUB)) {
				rv32i_sub(inst, state);
			}
			else if (matchFunct7(instruction, FUNCT7_ADD)) {
				rv32i_add(inst, state);
			}
		}
		else if (matchFunct3(instruction, FUNCT3_SLT)) {
			rv32i_slt(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_SLTU)) {
			rv32i_sltu(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_XOR)) {
			rv32i_xor(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_SRLA)) {
			if (matchFunct7(instruction, FUNCT7_SRL)) {
				rv32i_srl(inst, state);
			}
			else if (matchFunct7(instruction, FUNCT7_SRA)) {
				rv32i_sra(inst, state);
			}
		}
		else if (matchFunct3(instruction, FUNCT3_SLL)) {
			rv32i_sll(inst, state);
		}
	}
	else if (matchOpcode(instruction, OP_COMPI)) {
		IInstruction inst = IInstruction::parseI(instruction);
		if (matchFunct3(instruction, FUNCT3_ADD)) {
			rv32i_addi(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_SLT)) {
			rv32i_slti(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_SLTU)) {
			rv32i_sltiu(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_XOR)) {
			rv32i_xori(inst, state);
		}
		else  {
			RInstruction rinst = RInstruction::parseR(instruction);
			if (matchFunct3(instruction, FUNCT3_SRLA)) {
				if (matchFunct7(instruction, FUNCT7_SRL)) {
					rv32i_srli(rinst, state);
				}
				else if (matchFunct7(instruction, FUNCT7_SRA)) {
					rv32i_srai(rinst, state);
				}
			}
			else if (matchFunct3(instruction, FUNCT3_SLL)) {
				rv32i_slli(rinst, state);
			}
		}
	}
	else if (matchOpcode(instruction, OP_JAL)) {
		UInstruction inst = UInstruction::parseJ(instruction);
		rv32i_jal(inst, state);
	}
	else if (matchOpcode(instruction, OP_JALR)) {
		IInstruction inst = IInstruction::parseI(instruction);
		rv32i_jalr(inst, state);
	}
	else if (matchOpcode(instruction, OP_LOAD)) {
		IInstruction inst = IInstruction::parseI(instruction);
		if (matchFunct3(instruction, FUNCT3_LB)) {
			rv32i_lb(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_LH)) {
			rv32i_lh(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_LW)) {
			rv32i_lw(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_LBU)) {
			rv32i_lbu(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_LHU)) {
			rv32i_lhu(inst, state);
		}
	}
	else if (matchOpcode(instruction, OP_STORE)) {
		SInstruction inst = SInstruction::parseS(instruction);
		if (matchFunct3(instruction, FUNCT3_SB)) {
			rv32i_sb(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_SH)) {
			rv32i_sh(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_SW)) {
			rv32i_sw(inst, state);
		}
	}
	else if (matchOpcode(instruction, OP_LUI)) {
		UInstruction inst = UInstruction::parseU(instruction);
		rv32i_lui(inst, state);
	}
	else if (matchOpcode(instruction, OP_FENCE)) {
		IInstruction inst = IInstruction::parseI(instruction);
		if (matchFunct3(instruction, FUNCT3_FENCE)) {
			rv32i_fence(inst, state);
		}
		else if (matchFunct3(instruction, FUNCT3_FENCEI)) {
			rv32i_fencei(inst, state);
		}
	}
}
#include "catch.hpp"

#include "../src/instruction.hpp"

TEST_CASE("RInstruction") {
    uint32_t i = (0b0000000 << 25) // func7
        | (2 << 20) // rs2
        | (1 << 15) // rs1
        | (0b000 << 12) // funct3
        | (3 << 7) // rd
        | 0b0110011; // opcode
    RInstruction r_instruction = RInstruction::parseR(i);
    REQUIRE(r_instruction.opcode == 0b0110011);
    REQUIRE(r_instruction.rd == 3);
    REQUIRE(r_instruction.funct3 == 0b000);
    REQUIRE(r_instruction.rs1 == 1);
    REQUIRE(r_instruction.rs2 == 2);
    REQUIRE(r_instruction.funct7 == 0b0000000);
}

TEST_CASE("IInstruction") {
    uint32_t i = (1 << 20) // imm
        | (1 << 15) // rs1
        | (0b000 << 12) // funct3
        | (2 << 7) // rd
        | 0b0010011; // opcode
    IInstruction i_instruction = IInstruction::parseI(i);
    REQUIRE(i_instruction.opcode == 0b0010011);
    REQUIRE(i_instruction.rd == 2);
    REQUIRE(i_instruction.funct3 == 0b000);
    REQUIRE(i_instruction.rs1 == 1);
    REQUIRE(i_instruction.imm == 1);
}

TEST_CASE("SInstruction") {
    uint32_t i = (1 << 25) // imm
        | (2 << 20) // rs2
        | (1 << 15) // rs1
        | (0b000 << 12) // funct3
        | (0b10001 << 7) // imm
        | 0b0100011; // opcode
    SInstruction s_instruction = SInstruction::parseS(i);
    REQUIRE(s_instruction.opcode == 0b0100011);
    REQUIRE(s_instruction.funct3 == 0b000);
    REQUIRE(s_instruction.rs1 == 1);
    REQUIRE(s_instruction.rs2 == 2);
    REQUIRE(s_instruction.imm == 0b000000110001);

    SInstruction b_instruction = SInstruction::parseB(i);
    REQUIRE(b_instruction.opcode == 0b0100011);
    REQUIRE(b_instruction.funct3 == 0b000);
    REQUIRE(b_instruction.rs1 == 1);
    REQUIRE(b_instruction.rs2 == 2);
    REQUIRE(b_instruction.imm == 0b0100000110000);
}

TEST_CASE("UInstruction") {
    uint32_t imm = 0b01000000001110000001;
    uint32_t i = (imm << 12) // imm
        | (1 << 7) // rd
        | 0b0110111; // opcode
    UInstruction u_instruction = UInstruction::parseU(i);
    REQUIRE(u_instruction.opcode == 0b0110111);
    REQUIRE(u_instruction.imm == imm << 12);

    UInstruction j_instruction = UInstruction::parseJ(i);
    REQUIRE(j_instruction.opcode == 0b0110111);
    REQUIRE(j_instruction.imm == 0b010000001110000000010);
}

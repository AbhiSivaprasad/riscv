#include "catch.hpp"

#include "../src/cpustate.hpp"

TEST_CASE("Memory") {
    CPUState state;
    state.set_mem8(0, 0x0d);
    state.set_mem8(1, 0x0c);
    state.set_mem8(2, 0x0b);
    state.set_mem8(3, 0x0a);
    REQUIRE(state.get_mem8(0) == 0x0d);
    REQUIRE(state.get_mem16(0) == 0x0c0d);
    REQUIRE(state.get_mem32(0) == 0x0a0b0c0d);
    state.set_mem16(0, 0x0c0d);
    state.set_mem16(2, 0x0a0b);
    REQUIRE(state.get_mem8(0) == 0x0d);
    REQUIRE(state.get_mem16(0) == 0x0c0d);
    REQUIRE(state.get_mem32(0) == 0x0a0b0c0d);
    state.set_mem32(0, 0x0a0b0c0d);
    REQUIRE(state.get_mem8(0) == 0x0d);
    REQUIRE(state.get_mem16(0) == 0x0c0d);
    REQUIRE(state.get_mem32(0) == 0x0a0b0c0d);
}

#include "catch.hpp"

#include "../src/util.hpp"

TEST_CASE("get_bits") {
    uint32_t x = 0b1010;
    REQUIRE(get_bits(x, 0, 1) == 0);
    REQUIRE(get_bits(x, 1, 1) == 0);
    REQUIRE(get_bits(x, 1, 2) == 1);
    REQUIRE(get_bits(x, 0, 2) == 0b10);
    REQUIRE(get_bits(x, 1, 4) == 0b101);
    REQUIRE(get_bits(x, 1, 0) == 0);
}

TEST_CASE("sign_extend") {
    REQUIRE(sign_extend(0, 0) == 0);
    REQUIRE(sign_extend(1, 0) == ~0);
    REQUIRE(sign_extend(0b10, 1) == ~1);
}

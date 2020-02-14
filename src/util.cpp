#include "util.hpp"

uint32_t get_bits(uint32_t x, unsigned int i, unsigned int j) {
    if (i > j) {
        return 0;
    }
    uint32_t mask = ~(~0U << (j - i));
    return (x >> i) & mask;
}

uint32_t sign_extend(uint32_t x, unsigned int i) {
    if (x & (0b1 << i)) {
        return x | (~0U << i);
    } else {
        return x;
    }
}

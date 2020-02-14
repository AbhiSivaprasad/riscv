#include "util.hpp"

uint32_t get_bits(uint32_t x, unsigned int i, unsigned int j) {
    if (i > j) {
        return 0;
    }
    uint32_t mask = UINT32_MAX ^ (UINT32_MAX << (j - i));
    return (x >> i) & mask;
}

#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <cstdint>

uint32_t get_bits(uint32_t x, unsigned int i, unsigned int j);
uint32_t sign_extend(uint32_t x, unsigned int i);

#endif

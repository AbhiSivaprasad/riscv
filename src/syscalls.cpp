#include "syscalls.hpp"

#include <iostream>

uint32_t syscall_write(CPUState& state, uint32_t fd, uint32_t buf, uint32_t n) {
    uint32_t a = 0;
    if (fd == 1) {
        while (a < n) {
            char c = state.get_mem8(buf);
            std::cout << c;
            buf++;
            a++;
        }
        return a;
    }
    return -1;
}

#include "os.hpp"

void print(char *buf) {
    // r23, is a caller saved register
    // order of instructions is critical so use volatile
    /*
    __asm__ volatile (
        "ori 23,0,0"
        "ori 23,23,%2"
        "sh 23,10(0)"
        "ori 23,0,0"
        "lui 23,%3"
        "ori 23,23,%4"
        "sw 23,12(0)"
        "ori 23,0,0"
        "auipc 23,0"
        "addi 23,23,16"
        "sw 23,16(0)"
        "jalr 23,0,0"
        :
        : "r" (SYSCALL_PRINTF, (buf >> 12), (buf << 20) >> 20)
    );
    */
}

#include "os.hpp"

void print(char *buf) {
	// r23, r24 are caller saved registers
	// order of instructions is critical so use volatile
	__asm__ volatile (
		"lui 23,%2"
		"sh 23,10(0)"
		"lui 23,%3"
		"sw 23, 12(0)"
		"auipc 24, 0"
		"addi 23, 24, 16"
		"sw 23, 16(0)"
		"jalr 24, 0, 0"
		: 
		: "r" (SYSCALL_PRINTF, buf)
	);
}
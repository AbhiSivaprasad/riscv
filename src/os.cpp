#include <stdio.h>

#include "os.hpp"
#include "cpustate.hpp"

void load_elf(CPUState& state) {}

void handle_syscall(CPUState& state, uint32_t syscall_addr) {
	uint32_t syscall_id = state.get_x(SYSCALL_ARG_REG);
	uint32_t arg = state.get_x(SYSCALL_ARG_REG);
	switch (syscall_id) {
	case SYSCALL_PRINTF:
		handle_printf(state, arg);
		break;
	default:
		printf("Invalid syscall address: %d", syscall_addr);
	}
}

void handle_printf(CPUState& state, uint32_t buf_addr) {
	uint8_t byte;

	// print each character until '\0'
	while ((byte = state.get_mem8(buf_addr++))) {
		putchar(byte);
	}
}
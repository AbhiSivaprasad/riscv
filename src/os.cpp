#include <stdio.h>

#include "os.hpp"
#include "cpustate.hpp"

void load_elf(CPUState& state) {}

void handle_syscall(CPUState& state) {
	// get syscall info according to calling convention
	uint32_t syscall_id = state.get_mem16(SYSCALL_ARG_ADDR);
	uint32_t arg = state.get_mem32(SYSCALL_ARG_ADDR);
	uint32_t return_addr = state.get_mem32(SYSCALL_RETURN_ADDR);

	// dispatch syscall to handler
	switch (syscall_id) {
	case SYSCALL_PRINTF:
		handle_printf(state, arg);
		break;
	default:
		printf("Invalid syscall id: %d", syscall_id);
	}

	// set pc back to return address
	state.set_pc(return_addr);
}

void handle_printf(CPUState& state, uint32_t buf_addr) {
	uint8_t byte;

	// print each character until '\0'
	while ((byte = state.get_mem8(buf_addr++))) {
		putchar(byte);
	}
}
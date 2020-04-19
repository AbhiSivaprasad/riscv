#ifndef __OS_HPP__
#define __OS_HPP__

#include "cpustate.hpp"

// OS memory map
#define KERNEL_ENTRY_ADDR 0     // entry point into kernel for syscalls
#define PROCESS_START_ADDR 1000 // process address space

#define SYSCALL_ID_ADDR 10      // register 23 holds id of syscall
#define SYSCALL_ARG_ADDR 12     // register 24 holds arg for syscalls
#define SYSCALL_RETURN_ADDR 16  // register 25 holds return address

// identifiers for syscalls
#define SYSCALL_PRINTF 1

void handle_syscall(CPUState &state);
void handle_printf(CPUState &state, uint32_t buf_addr);

#endif

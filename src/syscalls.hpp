#ifndef __SYSCALLS_HPP__
#define __SYSCALLS_HPP__

#include "cpustate.hpp"

#define SYSCALL_WRITE 64

uint32_t syscall_write(CPUState& state, uint32_t fd, uint32_t buf, uint32_t n);

#endif

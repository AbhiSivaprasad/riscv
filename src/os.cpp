#include "os.hpp"

#include "syscalls.hpp"

// XXX
#include <iostream>

void handle_syscall(CPUState& state) {
    uint32_t syscall = state.get_x(17);
    uint32_t arg0 = state.get_x(10);
    uint32_t arg1 = state.get_x(11);
    uint32_t arg2 = state.get_x(12);
    // uint32_t arg3 = state.get_x(13);
    // uint32_t arg4 = state.get_x(14);
    // uint32_t arg5 = state.get_x(15);
    // uint32_t arg6 = state.get_x(16);
    uint32_t ret;
    switch (syscall) {
        case SYSCALL_WRITE:
            ret = syscall_write(state, arg0, arg1, arg2);
            break;
        default:
            std::string err = "unknown syscall " + std::to_string(syscall);
            throw err.c_str();
    }
    state.set_x(10, ret);
    return;
}

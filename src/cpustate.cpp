#include "cpustate.hpp"

void CPUState::set_x_register(int i, uint32_t val) {
    if (i == 0) {
        return;
    }
    x_registers[i - 1] = val;
}

uint32_t CPUState::get_x_register(int i) {
    if (i == 0) {
        return 0;
    }
    return x_registers[i - 1];
}

void CPUState::set_pc(uint32_t val) {
    pc = val;
}

uint32_t CPUState::get_pc() {
    return pc;
}

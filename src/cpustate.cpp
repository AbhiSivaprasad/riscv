#include "cpustate.hpp"

#include <iostream>

uint32_t CPUState::get_x(int i) const {
    if (i == 0) {
        return 0;
    }
    return x_regs[i - 1];
}

void CPUState::set_x(int i, uint32_t val) {
    if (i == 0) {
        return;
    }
    x_regs[i - 1] = val;
}

uint32_t CPUState::get_pc() const {
    return pc;
}

void CPUState::set_pc(uint32_t val) {
    pc = val;
}

uint8_t CPUState::get_mem8(uint32_t addr) const {
    return mem[addr];
}

void CPUState::set_mem8(uint32_t addr, uint8_t val) {
    mem[addr] = val;
}

uint16_t CPUState::get_mem16(uint32_t addr) const {
    return get_mem8(addr) | (get_mem8(addr + 1) << 8);
}

void CPUState::set_mem16(uint32_t addr, uint16_t val) {
    set_mem8(addr, val & 0xFF);
    set_mem8(addr + 1, val >> 8);
}

uint32_t CPUState::get_mem32(uint32_t addr) const {
    return get_mem16(addr) | (get_mem16(addr + 2) << 16);
}

void CPUState::set_mem32(uint32_t addr, uint32_t val) {
    set_mem16(addr, val & 0xFFFF);
    set_mem16(addr + 2, val >> 16);
}

std::ostream& operator<<(std::ostream& os, const CPUState& state) {
    os << "CPUState {\n";
    for (int i = 0; i < 32; i++) {
        os << "\tx" << i << ": " << state.get_x(i) << "\n";
    }
    os << "\n";
    os << "\tpc: " << state.get_pc() << "\n";
    os << "}";
    return os;
}

#ifndef __CPUSTATE_HPP__
#define __CPUSTATE_HPP__

#include <cstdint>
#include <array>

class CPUState {
    std::array<uint32_t, 31> x_registers = { 0 };
    uint32_t pc = 0;

    public:
    void set_x(int i, uint32_t val);
    uint32_t get_x(int i);
    void set_pc(uint32_t val);
    uint32_t get_pc();
};

#endif

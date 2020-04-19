#ifndef __CPUSTATE_HPP__
#define __CPUSTATE_HPP__

#include <cstdint>
#include <array>

#define MEMORY_SIZE (1000000)

class CPUState {
    std::array<uint32_t, 31> x_regs = {0};
    uint32_t pc = 0;
    std::array<uint8_t, MEMORY_SIZE> mem = {0};

    public:
    uint32_t get_x(int i) const;
    void set_x(int i, uint32_t val);
    uint32_t get_pc() const;
    void set_pc(uint32_t val);
    uint8_t get_mem8(uint32_t addr) const;
    void set_mem8(uint32_t addr, uint8_t val);
    uint16_t get_mem16(uint32_t addr) const;
    void set_mem16(uint32_t addr, uint16_t val);
    uint32_t get_mem32(uint32_t addr) const;
    void set_mem32(uint32_t addr, uint32_t val);
};

std::ostream &operator<<(std::ostream &os, const CPUState &state);

#endif

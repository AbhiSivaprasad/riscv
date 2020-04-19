#ifndef __CPUSTATE_HPP__
#define __CPUSTATE_HPP__

#include <cstdint>
#include <map>

#define PAGE_SIZE (12)

class CPUState {
    std::array<uint32_t, 31> x_regs = {0};
    uint32_t pc = 0;
    std::map<uint32_t, uint8_t*> mem;

    uint8_t* memmap(uint32_t addr);

    public:
    uint32_t get_x(int i) const;
    void set_x(int i, uint32_t val);
    uint32_t get_pc() const;
    void set_pc(uint32_t val);
    uint8_t get_mem8(uint32_t addr);
    void set_mem8(uint32_t addr, uint8_t val);
    uint16_t get_mem16(uint32_t addr);
    void set_mem16(uint32_t addr, uint16_t val);
    uint32_t get_mem32(uint32_t addr);
    void set_mem32(uint32_t addr, uint32_t val);
};

std::ostream& operator<<(std::ostream& os, const CPUState& state);

#endif

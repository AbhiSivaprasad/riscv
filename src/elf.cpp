#include "elf.hpp"

#include <elfio/elfio.hpp>

bool load_elf(char* file, CPUState& state) {
    ELFIO::elfio reader;
    if (!reader.load(file)) {
        return false;
    }

    for (auto segment : reader.segments) {
        if (segment->get_type() == PT_LOAD) {
            uint32_t addr = segment->get_virtual_address();
            uint32_t size = segment->get_file_size();
            const uint8_t* data = (const uint8_t*)segment->get_data();
            for (uint32_t i = 0; i < size; i++) {
                state.set_mem8(addr + i, data[i]);
            }
        }
    }

    uint32_t entry = reader.get_entry();
    state.set_pc(entry);

    return true;
}

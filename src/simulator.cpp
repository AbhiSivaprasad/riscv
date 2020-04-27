#include <iostream>
#include <fstream>

#include "cpustate.hpp"
#include "dispatch.hpp"
#include "elf.hpp"

int main(int argc, char* argv[]) {
    CPUState state;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " executable\n";
        return 1;
    }

    if (!load_elf(argv[1], state)) {
        std::cerr << "Failed to load " << argv[1] << "\n";
        exit(1);
    }

    std::cout << "Loaded " << argv[1] << "\n";

    std::cout << "Start state:\n" << state << "\n";

    while (1) {
        try {
            // fetch instruction
            uint32_t instruction = state.get_mem32(state.get_pc());

            // decode + execute instruction
            if (!dispatch(instruction, state)) {
                break;
            }

            // increment program counter
            state.set_pc(state.get_pc() + 4);
        } catch (const char* e) {
            std::cerr << e << "\n";
            exit(1);
        }
    }

    std::cout << "End state:\n" << state << "\n";
}

#include <iostream>
#include <fstream>

#include "cpustate.hpp"
#include "dispatch.hpp"
#include "elf.hpp"
#include "os.hpp"

int main(int argc, char* argv[]) {
    CPUState state;       // initialized state

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " executable\n";
        return 1;
    }

    /* std::ifstream file(argv[1], std::ios::binary); */
    /* if (!file.is_open()) { */
    /*     std::cerr << "Failed to open " << argv[1] << "\n"; */
    /*     return 1; */
    /* } */
    /* programSize = 0; */
    /* char b; */
    /* while (file.get(b)) { */
    /*     state.set_mem8(PROCESS_START_ADDR + programSize, b); */
    /*     programSize++; */
    /* } */

    /* if (programSize % 4 != 0) { */
    /*     std::cerr << "Program size not 32 bit aligned\n"; */
    /*     return 1; */
    /* } */

    /* finalAddr = PROCESS_START_ADDR + programSize; */

    if (!load_elf(argv[1], state)) {
        std::cerr << "Failed to load " << argv[1] << "\n";
    }

    std::cout << "Loaded " << argv[1] << "\n";

    std::cout << "Starting pc " << state.get_pc() << "\n";

    while (1) {
        std::cout << state << "\n";
        try {
            // current program counter
            uint32_t pc = state.get_pc();

            // check if instruction is a syscall
            /* if (pc == KERNEL_ENTRY_ADDR) { */
            /*     // handle system call */
            /*     handle_syscall(state); */
            /*     continue; */
            /* } */

            // instruction isn't a syscall, fetch from memory
            // fetch instruction
            uint32_t instruction = state.get_mem32(pc);

            // decode + execute instruction
            if (dispatch(instruction, state)) {
                // increment program counter
                state.set_pc(pc + 4);
            }
            /* std::cout << state << "\n"; */
        } catch (const char* e) {
            std::cerr << e << "\n";
            exit(1);
        }
    }
}

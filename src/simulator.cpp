#include <iostream>
#include <fstream>

#include "os.hpp"
#include "cpustate.hpp"
#include "dispatch.hpp"

int main(int argc, char *argv[]) {
    CPUState state;       // initialized state
    uint32_t programSize; // size of code segment
    uint32_t finalAddr;   // address of last instruction to execute

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " executable\n";
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << argv[1] << "\n";
        return 1;
    }
    programSize = 0;
    char b;
    while (file.get(b)) {
        state.set_mem8(PROCESS_START_ADDR + programSize, b);
        programSize++;
    }

    if (programSize % 4 != 0) {
        std::cerr << "Program size not 32 bit aligned\n";
        return 1;
    }

    finalAddr = PROCESS_START_ADDR + programSize;
    state.set_pc(PROCESS_START_ADDR);
    while (1) {
        // current program counter
        uint32_t pc = state.get_pc();

        // check if instruction is a syscall
        if (pc == KERNEL_ENTRY_ADDR) {
            // handle system call
            handle_syscall(state);
            continue;
        }

        // instruction isn't a syscall, fetch from memory
        // fetch instruction
        uint32_t instruction = state.get_mem32(pc);

        // decode + execute instruction
        dispatch(instruction, state);

        // if final instruction has been executed then break
        if (pc + 4 == finalAddr) {
            break;
        }

        // increment program counter
        state.set_pc(pc + 4);
    }
    std::cout << "x3: " << state.get_x(3) << "\n";
}


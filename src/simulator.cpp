#include <fstream>
#include <getopt.h>
#include <iostream>

#include "cpustate.hpp"
#include "dispatch.hpp"
#include "elf.hpp"

int main(int argc, char* argv[]) {
    int print_start_state = false;
    int print_end_state = false;
    int print_state = false;

    struct option options[] = {
        { "start-state", false, &print_start_state, true},
        { "end-state", false, &print_end_state, true},
        { "state", false, &print_state, true},
        { NULL, false, NULL, false},
    };

    while (getopt_long_only(argc, argv, "", options, NULL) != -1);

    char* exe = argv[optind];
    if (!exe) {
        std::cerr << "Usage: " << argv[0] << " [--start-state] [--end-state] [--state] executable\n";
        return 1;
    }

    CPUState state;
    if (!load_elf(exe, state)) {
        std::cerr << "Failed to load " << exe << "\n";
        exit(1);
    }
    std::cerr << "Loaded " << exe << "\n";

    if (print_start_state) {
        std::cerr << "Start state:\n" << state << "\n";
    }

    while (1) {
        try {
            if (print_state) {
                std::cerr << state << "\n";
            }

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

    if (print_end_state) {
        std::cerr << "End state:\n" << state << "\n";
    }
}

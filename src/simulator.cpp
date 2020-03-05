#include <iostream>

#include "os.hpp"
#include "cpustate.hpp"
#include "dispatch.hpp"


int main() {
    CPUState state;       // initialized state
    uint32_t programSize; // size of code segment
    uint32_t finalAddr;   // address of last instruction to execute

    // TODO: load interrupt routine into memory 

    // TODO: load binary into memory
    finalAddr = PROCESS_START_ADDR + programSize;

    while (1) {
        // current program counter
        uint32_t pc = state.get_pc();

        // fetch instruction 
        uint32_t instruction = state.get_mem32(pc);

        // decode + execute instruction
        dispatch(instruction, state);

        // if final instruction has been executed then break
        if (pc == finalAddr) {
            break;
        }

        // increment program counter
        state.set_pc(pc + 4);
    }
}

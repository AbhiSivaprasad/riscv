#include <iostream>

#include "cpustate.hpp"

int main() {
    CPUState state;
    state.set_x_register(2, 5);
    std::cout << state.get_x_register(2) << "\n";
}

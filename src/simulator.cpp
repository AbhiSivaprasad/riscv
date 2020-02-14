#include <iostream>

#include "cpustate.hpp"

int main() {
    CPUState state;
    state.set_x(2, 5);
    std::cout << state.get_x(2) << "\n";
}

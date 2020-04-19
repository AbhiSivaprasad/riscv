#ifndef __ELF_HPP__
#define __ELF_HPP__

#include "cpustate.hpp"

bool load_elf(char* file, CPUState& state);

#endif

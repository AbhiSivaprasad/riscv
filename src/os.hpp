// OS memory map
#define KERNEL_ENTRY_ADDR 0      // entry point into kernel for syscalls
#define PROCESS_START_ADDR 1000  // process address space

#define SYSCALL_ID_REG 23		 // register 23 holds id of syscall
#define SYSCALL_ARG_REG 24		 // register 24 holds arg for syscalls

// identifiers for syscalls 
#define SYSCALL_PRINTF 1

void load_elf(CPUState &state);  // add elf datastructure as arg
void handle_syscall(CPUState& state, uint32_t syscall_addr);
void handle_printf(CPUState& state, uint32_t buf_addr)
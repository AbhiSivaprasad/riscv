src = files(
  'cpustate.cpp',
  'instruction.cpp',
  'ops.cpp',
  'util.cpp',
)
riscv_lib = shared_library('riscv', src)
executable('simulator', 'simulator.cpp', link_with: riscv_lib)

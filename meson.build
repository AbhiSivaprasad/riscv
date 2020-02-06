project(
  'riscv',
  'cpp',
  version: '0.0.1',
  default_options: [
    'cpp_std=c++17',
    'warning_level=3',
    'werror=true',
  ],
)
src = files([
  'src/cpustate.cpp',
  'src/simulator.cpp',
])
executable('riscv-simulator', src)

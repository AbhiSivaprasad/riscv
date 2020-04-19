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
incdir = include_directories('include')
subdir('src')
subdir('test')
executable('simulator', 'src/simulator.cpp', link_with: riscv_lib)

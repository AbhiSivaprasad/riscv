src = files(
  'instruction.cpp',
  'cpustate.cpp',
  'main.cpp',
  'util.cpp',
)
test_exe = executable('tests', src, link_with: riscv_lib)
test('unit', test_exe)

The [riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain) was compiled with configuration options `--with-arch=rv32ia`.

Each example is then compiled with the following commands:
```
$ cd examples/{example}
$ riscv32-unknown-linux-gcc -nostdlib ../start.S main.c
```
The standard library is not included due to it calling many unsupported system calls.
The `start.S` file provides a basic entry into main to replace that provided by the standard library.

Each example can be run in the simulator with the following command:
```
$ ./build/simulator examples/{example}/a.out
```

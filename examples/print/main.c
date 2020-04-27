#include <stdio.h>

ssize_t write(int fd, const void* buf, size_t n) {
    ssize_t ret;
    __asm__ (
        "li a7,64;"
        "mv a0,%1;"
        "mv a1,%2;"
        "mv a2,%3;"
        "ecall;"
        "mv %0,a0;"
        : "=r" (ret)
        : "r" (fd), "r" (buf), "r" (n)
    );
    return ret;
}

int puts(const char* s) {
    char* nl = "\n";
    size_t len = 0;
    for (const char* c = s; *c; c++) {
        len++;
    }
    write(1, s, len);
    write(1, nl, 1);
    return 0;
}

int main() {
    puts("Hello, world!");
}

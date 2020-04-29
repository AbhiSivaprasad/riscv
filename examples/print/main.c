long write(int fd, const void* buf, unsigned int size) {
    long ret;
    __asm__ (
        "li a7,64;"
        "mv a0,%1;"
        "mv a1,%2;"
        "mv a2,%3;"
        "ecall;"
        "mv %0,a0;"
        : "=r" (ret)
        : "r" (fd), "r" (buf), "r" (size)
    );
    return ret;
}

unsigned long strlen(const char* s) {
    unsigned int len = 0;
    for (const char* c = s; *c; c++) {
        len++;
    }
    return len;
}

long puts(const char* s) {
    return write(1, s, strlen(s));
}

void reverse(char* s) {
    for (unsigned long i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

// converts to base16
char* itoa(int n, char* s) {
    if (n == 0) {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    int is_neg = 0;
    if (n < 0) {
        n = -n;
        is_neg = 1;
    }
    int i = 0;
    while (n) {
        int r = n & 0xf;
        if (r < 10) {
            s[i] = '0' + r;
        } else {
            s[i] = 'a' + r;
        }
        i++;
        n = n >> 4;
    }
    if (is_neg) {
        s[i] = '-';
        i++;
    }
    s[i] = '\0';
    reverse(s);
    return s;
}

int main() {
    puts("This is the print example\n");
    int a = 1;
    int b = 2;
    int c = a + b;
    char buf[256];
    puts("1 + 2 = ");
    puts(itoa(c, buf));
    puts("\n");
}

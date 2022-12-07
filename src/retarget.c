#include <stddef.h>
#include <sys/stat.h>
#include "device.h"

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _lseek(int file, int offset, int whence) {
    return 0;
}

int _close(int fd) {
    return -1;
}

int _write(int fd, char *buf, size_t size) {
    if (fd == 1) {  // stdout
        UART_Transmit(buf, size);
    }
    return size;
}

int _read (int fd, char *buf, int count) {
    int read = 0;

    for (; count > 0; --count) {
        while (!UART_Available());
        *buf++ = UART_RingGet();
        read++;
    }

    return read;
}

void *_sbrk(int incr) {
    extern char _end[];
    extern char _estack[];
    static char * heap = _end;
    char * base;

        base  = heap;
        heap += incr;

    return base;
}

void _exit(int status) {
    __asm("BKPT #0");
}

void _kill(int pid, int sig) {
    return;
}

int _getpid(void) {
    return -1;
}

int _isatty(int file) {
    return 1;
}



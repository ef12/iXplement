#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#undef errno
extern int errno;

void _exit(int status)
{
    while (1) { ; }  // Hang here indefinitely
}

int _kill(pid_t pid, int sig)
{
    errno = EINVAL;
    return -1;
}

pid_t _getpid(void)
{
    return 1;
}

int _write(int file, char *ptr, int len)
{
    return len;
}

int _close(int file)
{
    return -1;
}

int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file)
{
    return 1;
}

int _lseek(int file, int ptr, int dir)
{
    return 0;
}

int _read(int file, char *ptr, int len)
{
    return 0;
}

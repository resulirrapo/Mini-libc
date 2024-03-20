#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

//here i followed the same implementation as in the read_write function
int nanosleep(const struct timespec *t1, struct timespec *t2) {
    int ret = syscall(35, t1, t2);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return 0;
}

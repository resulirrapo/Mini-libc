#include <sys/stat.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tm_sec = seconds;
    req.tm_nsec = 0;

    if (nanosleep(&req, &rem) == -1) {
        return rem.tm_sec;  // Continue sleeping for the remaining time
    }
    return 0;  // Return 0 to indicate that the requested time has elapsed
}

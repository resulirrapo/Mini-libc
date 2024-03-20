#ifndef _TIME_H
#define _TIME_H

#ifdef __cplusplus
extern "C" {
#endif

typedef long time_t;

struct timespec {
    time_t tm_sec;  /* Seconds */
    long   tm_nsec; /* Nanoseconds */
};

// Function declarations

// Returns the current calendar time encoded as a time_t object, and also stores it in the memory pointed by timer.
time_t time(time_t *timer);

// Returns the difference between two calendar times (in seconds).
double difftime(time_t time1, time_t time0);

// Fills a timespec structure with the current time.
int clock_gettime(struct timespec *tp);

// Sets the current time using a timespec structure.
int clock_settime(const struct timespec *tp);

// Converts the calendar time time to broken-down time representation.
struct timespec *gmtime_r(const time_t *timep);

// ... other function declarations ...

int nanosleep(const struct timespec *t1, struct timespec *t2);

#ifdef __cplusplus
}
#endif

#endif /* _TIME_H */


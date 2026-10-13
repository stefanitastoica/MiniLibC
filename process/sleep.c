#include <internal/types.h>
#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int sec)
{
    struct timespec req, rem;
    req.tv_sec = sec;
    req.tv_nsec = 0;
    long ret;
    ret = nanosleep(&req, &rem);
    return ret;
}

#include <internal/types.h>
#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int ret;
    ret = syscall(35, req, rem);
    return ret;
}

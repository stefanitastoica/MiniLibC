// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <string.h>
//#include <cstdio>
void puts(const char *s)
{
    size_t len = strlen(s);
    write(1, s, len);
    write(1, "\n", 1);
}

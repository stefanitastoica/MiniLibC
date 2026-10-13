// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;
	int ret;
	ret = syscall(257, AT_FDCWD, filename, flags, mode);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
	/* TODO: Implement open system call. */
}

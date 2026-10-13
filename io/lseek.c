// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	if (fd < 0) return -1;
	if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) {
    	errno = EINVAL;
    	return -1;
	}
	int ret = syscall(8, fd, offset, whence);
	if (ret < 0)
		return -1;
	return ret;
}

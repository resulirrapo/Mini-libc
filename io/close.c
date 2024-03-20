// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	//here i followed the same implementation as in the read_write function
	int ret = syscall(3, fd);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}


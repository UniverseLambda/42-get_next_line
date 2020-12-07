#include <stddef.h>
#include <stdlib.h>

	void *ft_malloc(size_t size)
{
	static int count = 0;

	if (count == 0) {
		return NULL;
	}
	++count;
	return malloc(size);
}
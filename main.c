#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

#include "get_next_line.h"

// FIXME: REMOVE THAT SHIT
#include "get_next_line.c"
#include "get_next_line_utils.c"

int main(int argc, char **argv)
{
	int fd;
	if (argc <= 1)
	{
		fd = STDIN_FILENO;
	}
	else
	{
		fd = fileno(fopen(argv[1], "r"));
	}
	
	size_t count = 0;
	char *line;
	int result;
	while ((result = get_next_line(fd, &line)) == 1)
	{
		++count;
		free(line);
	}
	printf("%zu\n", count);
	close(fd);
	return (result);
}
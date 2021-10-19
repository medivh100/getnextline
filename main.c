#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *string;
	int c;

	c = 0;
	fd = open("text.txt", O_RDONLY);
	while (c < 4)
	{
		string = get_next_line(fd);
		printf("%s", string);
		free(string);
	 	c++;
	}
	return (0);
}
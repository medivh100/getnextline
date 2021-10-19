#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

size_t	checkchar(char *s, size_t index)
{
	while (s[index++])
	{
		if (s[index] == '\n')
			return (1);
	}
	return (0);
}

char    *get_next_line(int fd)
{
	static char		*str;
	static char		buf[BUFFER_SIZE + 1];
	static size_t	index;
	size_t			count;

	count = 0;
	if (fd == -1)
		return (NULL);
	if (index == 0)
		str = malloc(sizeof(char *));
	while ((read(fd, buf, BUFFER_SIZE)) > 0)
	{
		str = ft_strjoin(str, buf);
		if (checkchar(str, index) == 0)
			count++;
		else if (checkchar(str, index) == 1)
		{
			index += (count + 1);
			return (ft_substr(str, (index - (count + 1)), count + 1));
		}
	}
	index += (count + 1);
	return (ft_substr(str, (index - (count + 1)), count + 1));
	return (NULL);
}
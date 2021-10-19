#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

size_t	findline(char *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index++])
	{
		if (s[index] == c)
			return (1);
	}
	return (0);
}

char	*re_alloc(char *s, char *nstr)
{
	free(s);
	return (nstr);
}

char *read_line(char *s, size_t *ptr)
{
	char	*nstr;
	size_t	count;
	size_t	index;

	index = *ptr;

	count = 0;
	while (s[index] != '\n')
	{
		count++;
		index++;
	}
	nstr = ft_substr(s, (index - count), count + 1);
	*ptr = index;
	return (nstr);
}

char    *get_next_line(int fd)
{
	static char		*str;
	static char		buf[BUFFER_SIZE + 1];
	static size_t	index;

	if (fd == -1)
		return (NULL);
	if (index == 0)
		str = malloc(sizeof(char *));
	while (read(fd, buf, BUFFER_SIZE) != 0 || findline(buf, '\n') == 0)
	{
		str = re_alloc(str, ft_strjoin(str, buf));
		if (findline(str, '\n') == 1)
			break;
	}
	return (read_line(str, &index));
}
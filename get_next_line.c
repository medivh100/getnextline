#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

size_t	findline(char *s, char c, size_t *i)
{
	size_t	index;

	index = *i;
	while (s[index])
	{
		if (s[index] == c)
		{
			*i = index + 1;
			return (1);
		}
		index++;
	}
	*i = index;
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
	if (s[index] == '\0')
		return (NULL);
	while (s[index] != '\n' && s[index] != '\0')
	{
		count++;
		index++;
	}
	nstr = ft_substr(s, (index - count), count + 1);
	*ptr = index + 1;
	return (nstr);
}

char    *get_next_line(int fd)
{
	static char		*str;
	static char		buf[BUFFER_SIZE + 1];
	static size_t	index;
	static size_t	index2;
	static size_t	readchar;

	if (fd == -1)
		return (NULL);
	if (index == 0)
		str = malloc(sizeof(char *));
	while (((readchar += read(fd, buf, BUFFER_SIZE)) != 0))
	{
		str = re_alloc(str, ft_strjoin(str, buf));
		//str = re_alloc(str, ft_strdup(buf));
		if (findline(str, '\n', &index2) == 1)
			break;
	}
	if (index == readchar)
	{
		free(str);
		return (NULL);
	}
	return (read_line(str, &index));
}
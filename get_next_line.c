#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cd;
	unsigned char	cout;
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	cout = (unsigned char) c;
	cd = 0;
	while (cd < len)
	{
		*ptr = cout;
		ptr++;
		cd++;
	}
	return (b);
}

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

char *read_line(char *s, size_t *ptr, char *buf)
{
	char	*nstr;
	size_t	count;
	size_t	index;

	index = *ptr;
	count = 0;
	if (s[index] == '\0')
	{
		free(buf);
		free(s);
		return (NULL);
	}
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
	char			*buf;
	static size_t	index;
	static size_t	index2;
	size_t			res;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	str = malloc(sizeof(char));
	if (buf == NULL || str == NULL)
		return (NULL);
	if (!(res = read(fd, buf, BUFFER_SIZE)) && index == 0)
	{
		free(buf);
		free(str);
		return (NULL);
	}
	if (res < BUFFER_SIZE && index == 0)
		str = ft_strjoin(str, buf);
	while (res == BUFFER_SIZE && findline(str, '\n', &index2) == 0)
	{
		str = ft_strjoin(str, buf);
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		res = read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(str, &index, buf));
}

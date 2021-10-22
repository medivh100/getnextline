#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char *re_alloc(char *tofree)
{
	char *rstr;
	rstr = NULL;
	rstr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//printf("%s%p\n","L'adresse de rstr: ", rstr);
	free(tofree);
	return (rstr);
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
	free(buf);
	buf = NULL;
	return (nstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ns;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	ns = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	ft_strlcat(ns, s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	free((void*)s1);
	s1 = NULL;
	return (ns);
}

char    *get_next_line(int fd)
{
	static char		*str;
	char			*buf;
	char			*tmp;
	static size_t	index;
	static size_t	index2;

	buf = NULL;
	tmp = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if ((read(fd, buf, BUFFER_SIZE)) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (index == 0)
		str = malloc((BUFFER_SIZE) * sizeof(char));
	str = ft_strjoin(str, buf);
	buf = re_alloc(buf);
	//printf("%s%p %p\n","1: L'adresse de buf et str: ", buf, str);
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{
		str = ft_strjoin(str, buf);
		buf = re_alloc(buf);
		//printf("%s%p %p\n","2: L'adresse de buf et str: ", buf, str);
		if (findline(str, '\n', &index2) == 1)
			break;
	}
	buf = re_alloc(buf);
	tmp = read_line(str, &index, buf);
	return (tmp);
}

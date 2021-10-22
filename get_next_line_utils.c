#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;

	start = ft_strlen(dst);
	if (start + 1 > dstsize)
		return (ft_strlen(src) + dstsize);
	while (*src && start < (dstsize - 1))
	{
		dst[start] = *src;
		src++;
		start++;
	}
	dst[start] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cd;

	cd = 0;
	if (dstsize == 0)
	{
		while (src[cd])
			cd++;
		return (cd);
	}
	cd = 0;
	while (cd < dstsize - 1 && src[cd])
	{
		dst[cd] = src[cd];
		cd++;
	}
	if (dstsize != 0)
		dst[cd] = '\0';
	cd = 0;
	while (src[cd])
		cd++;
	return (cd);
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rs;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	while (i < len && s[i])
		i++;
	rs = malloc((i + 1) * sizeof(char));
	if (rs == NULL)
		return (NULL);
	ft_strlcpy(rs, s + start, len + 1);
	return (rs);
}

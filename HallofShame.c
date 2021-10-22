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
		free(s);
		free(buf);
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
	return (nstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ns;
	size_t		start;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	start = ft_strlen(s1);
	ns = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	ft_strlcat(ns, s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	free((void *)s1);
	return (ns);
}

char    *get_next_line(int fd)
{
	static char		*str;
	char			*buf;
	static size_t	index;
	static size_t	index2;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//check pour premiere iteration pour pas alloc str pour rien
	if (index == 0)
		str = malloc(sizeof(char));
	//test pour 
	if (!(read(fd, buf, BUFFER_SIZE)) && index == 0)
	{
		free(buf);
		free(str);
		return (NULL);
	}
	str = ft_strjoin(str, buf);
	free(buf);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{
		str = ft_strjoin(str, buf);
		free(buf);
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char)); 
		if (findline(str, '\n', &index2) == 1)
			break;
	}
	str = read_line(str, &index, buf);
	return (str);
}


// char    *get_next_line(int fd)
// {
// 	static char		*str;
// 	static char		buf[BUFFER_SIZE + 1];
// 	static size_t	index;
// 	static size_t	index2;
// 	//size_t			res;

// 	if (fd == -1)
// 		return (NULL);
// 	while (read(fd, buf, BUFFER_SIZE) != 0)
// 	{
// 		str = ft_strjoin(str, buf);
// 		if (findline(str, '\n', &index2) == 1)
// 			break;
// 	}
// 	return (read_line(str, &index));
// }

// char    *get_next_line(int fd)
// {
// 	static char		*str;
// 	static char		buf[BUFFER_SIZE + 1];
// 	static size_t	index;
// 	static size_t	index2;

// 	if (fd < 0 || fd > 5)
// 		return (NULL);
// 	if (index == 0)
// 		str = malloc(sizeof(char *));
// 	while (read(fd, buf, BUFFER_SIZE) != 0)
// 	{
// 		str = ft_strjoin(str, buf);
// 		ft_memset(buf, '\0', BUFFER_SIZE);
// 		if (findline(str, '\n', &index2) == 1)
// 			break;
// 	}
// 	return (read_line(str, &index));
// }

// // size_t	checkchar(char *s, size_t index)
// // {
// // 	while (s[index++])
// // 	{
// // 		if (s[index] == '\n')
// // 			return (1);
// // 	}
// // 	return (0);
// // }

// // char    *get_next_line(int fd)
// // {
// // 	static char		*str;
// // 	static char		buf[BUFFER_SIZE + 1];
// // 	static size_t	index;
// // 	size_t			count;
// // 	size_t			res;

// // 	count = 0;
// // 	if (fd == -1)
// // 		return (NULL);
// // 	if (index == 0)
// // 		str = malloc(sizeof(char *));
// // 	res = read(fd, buf, BUFFER_SIZE);
// // 	if (res == 0)
// // 		return (NULL);
// // 	while (res > 0)
// // 	{
// 		str = ft_strjoin(str, buf);
// 		if (checkchar(str, index) == 0)
// 			count++;
// 		else if (checkchar(str, index) == 1)
// 		{
// 			index += (count + 1);
// 			return (ft_substr(str, (index - (count + 1)), count + 1));
// 		}
// 		res = read(fd, buf, BUFFER_SIZE);
// 	}
// 	index += (count + 1);
// 	return (ft_substr(str, (index - (count + 1)), count + 1));
// }

// char    *get_next_line(int fd)
// {
//     static char     *str;
//     static char     buf[BUFFER_SIZE + 1];
//     static size_t   index;
//     size_t          count;
//     size_t          res;

//     count = 0;
//     if (fd == -1)
//         return (NULL);
//     if (index == 0)
//         str = malloc(sizeof(char *));
//     res = read(fd, buf, BUFFER_SIZE);
//     while (res > 0 || index <= res)
//     {
//         if (res > 0)
//             str = ft_strjoin(str, buf);
//         while (str[count++] != '\n' || str[count++] != '\0')
//         {
//             if (str[count] == '\n' || str[count] == '\0')
//             {
//                 index += count;
//                 return (ft_substr(str, index - count, count));
//             }
//         }
//         count = 0;
//     }
//     return (NULL);
// }

// char    *get_next_line(int fd)
// {
//     static char     *str;
//     static char     buf[BUFFER_SIZE + 1];
//     static size_t   index;
//     size_t          count;

//     count = 0;
//     if (fd == -1)
//         return (NULL);
//     if (index == 0)
//         str = malloc(sizeof(char *));
//     while (read(fd, buf, BUFFER_SIZE) > 0)
//         str = ft_strjoin(str, buf);
//     while (str[index++])
//     {
//         if (str[index] == '\n' || str[index] == '\0')
// 		{
// 			free(str);
// 			return (ft_substr(str, index - (count + 1), count + 1));
// 		}
//         count++;
//     }
// 	free(str);
//     return (NULL);
// }

// int	trigger(char *s, char c)
// {
// 	while (*s)
// 	{

// 	}
// }

// char *get_next_line(int fd)
// {
// 	static char 	*str;
// 	static char		*rstr;
// 	char     		buf[BUFFER_SIZE + 1];
// 	static size_t	index;
// 	size_t			count;

// 	if (fd == -1)
// 		return (NULL);
// 	if (index == 0)
// 		str = malloc(sizeof(char *));
// 	while((read(fd, buf, BUFFER_SIZE)) > 0)
// 	{
// 		str = ft_strjoin(str, buf);
// 		while (str[count++])
// 		{
// 			if (str[count] == '\n')
// 				break;	
// 			count++;
// 		}
// 		if (str[count] == '\n')
// 			break;
// 		count = 0;
// 	}
// 	return (ft_substr(str, 0, count + 1));
// }

// char    *get_next_line(int fd)
// {
//     static char     *str;
//     static char     buf[BUFFER_SIZE + 1];
//     static size_t   index;
//     size_t          count;

//     count = 0;
//     if (fd == -1)
//         return (NULL);
//     if (index == 0)
//         str = malloc(sizeof(char *));
//     while (read(fd, buf, BUFFER_SIZE) > 0)
//         str = ft_strjoin(str, buf);
//     while (str[index++])
//     {
//         if (str[index] == '\n' || str[index] == '\0')
//             return (ft_substr(str, index - (count + 1), count + 1));
//         count++;
//     }
//     return (NULL);
// }

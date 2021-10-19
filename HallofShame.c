// size_t	checkchar(char *s, size_t index)
// {
// 	while (s[index++])
// 	{
// 		if (s[index] == '\n')
// 			return (1);
// 	}
// 	return (0);
// }

// char    *get_next_line(int fd)
// {
// 	static char		*str;
// 	static char		buf[BUFFER_SIZE + 1];
// 	static size_t	index;
// 	size_t			count;
// 	size_t			res;

// 	count = 0;
// 	if (fd == -1)
// 		return (NULL);
// 	if (index == 0)
// 		str = malloc(sizeof(char *));
// 	res = read(fd, buf, BUFFER_SIZE);
// 	if (res == 0)
// 		return (NULL);
// 	while (res > 0)
// 	{
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

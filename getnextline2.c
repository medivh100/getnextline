#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd)
{
    static char     *str;
    static char     buf[BUFFER_SIZE + 1];
    static size_t   index;
    size_t          count;
    size_t          res;

    count = 0;
    if (fd == -1)
        return (NULL);
    if (index == 0)
        str = malloc(sizeof(char *));
    res = read(fd, buf, BUFFER_SIZE);
    while (res > 0 || index <= res)
    {
        if (res > 0)
            str = ft_strjoin(str, buf);
        while (str[count++] != '\n' || str[count++] != '\0')
        {
            if (str[count] == '\n' || str[count] == '\0')
            {
                index += count;
                return (ft_substr(str, index - count, count));
            }
        }
        count = 0;
    }
    return (NULL);
}
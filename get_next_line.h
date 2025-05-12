#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*strcopy(const char *src, int dstlen);
size_t	ft_strlen(const char *str);

#endif
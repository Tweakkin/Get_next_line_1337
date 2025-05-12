#include "get_next_line.h"


int	re_adjust_position(int *pos, char *buff, int fdlen)
{
	char *copy;
	int linelen;

	linelen = 0;
	copy = ft_strdup(buff);
	while (*pos < fdlen && copy[*pos] != '\n')
	{
		(*pos)++;
		linelen++;
	}
	free (copy);
	return (linelen);
}

size_t	handle_read_fdlen(int fd, char *buff)
{
	size_t	fdlen;

	fdlen = read(fd, buff, BUFFER_SIZE);
	if (fdlen <= 0)
		return 0;

	return (fdlen);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static size_t	fdlen;
	static int		position;
	char			*line;
	int				linelen;
	int 			start;

	if (fd < 0)
		return NULL;
	start = position;
	if (position == 0 || buff[position] == '\0')
		fdlen = handle_read_fdlen(fd, buff);
	if (fdlen <= 0 || position >= (int)fdlen)
		return NULL;
	linelen = re_adjust_position(&position, buff, (int)fdlen);
	line = strcopy(&buff[start], linelen);
	if (position < (int)fdlen && buff[position] == '\n') 
    	position++;
	return (line);
}

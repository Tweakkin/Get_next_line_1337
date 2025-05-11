#include "get_next_line.h"


int	re_adjust_position(int pos, int *linelen, char *buff, int fdlen)
{
	char *copy;

	copy = ft_strdup(buff);
	while (c[pos] != '\n' && pos < fdlen)
	{
		pos++;
		(*linelen)++;
	}
	return (pos);
}

char *get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	static size_t		fdlen = 0;
	static int position = 0;
	char *line = NULL;
	int linelen = 0;
	int c = 0;
	int	start = 0;
	
	if (fd <= 0)
		return NULL;
	start = position;
	printf("AT THE BEGINNING , position = %d\n", position);
	if (position >= (int)fdlen)
	{
		printf("ENTERED THE CONDITION\n");
		fdlen = read(fd, buff, BUFFER_SIZE);
		printf("FDLEN = %d\n", fdlen);
		if (fdlen <= 0)
		{
			printf("READ ERROR");
			return NULL;
		}
	}
	position = re_adjust_position(position, &linelen, buff, (int)fdlen);
	printf("IN CODE , position = %d AND LINELEN = %d\n", position, linelen);//positon = 16
	line = (char *)malloc(linelen + 1);
	if (!line)
		return (NULL);
	while (c < linelen)
	{
		line[c] = buff[start + c];
		c++;
	}
	line[linelen] = '\0';
	if (position < (int)fdlen && buff[position] == '\n') 
	{
		printf("ENTERS SEC COND");
    	position++;
	}
	printf("-------------\n");
	return (line);
}

/*int main()
{
	char *s="cups of the rose\nbs in my old phone\ni should call one and go home";
	printf("%s\n---------\n", s);
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, s, strlen(s));
	close(fd);
	fd = open("output.txt", O_RDONLY);
	char *c = get_next_line(fd);
	printf("FIRST CALL :\n%s\nthis strings contains %d chars", c, strlen(c));
	printf("\n-----------\n");
	char *k = get_next_line(fd);
	printf("SECOND CALL :\n%s\nthis strings contains %d chars", k, strlen(k));
	printf("\n-----------\n");
	char *f = get_next_line(fd);
	printf("THIRD CALL :\n%s\nthis strings contains %d chars", f, strlen(f));
	printf("\n-----------\n");
	char *v = get_next_line(fd);
	if (v != NULL) {
    printf("FOURTH CALL :\n%s\nthis strings contains %d chars", v, strlen(v));
	} 	else {
    printf("FOURTH CALL : End of file reached, no more lines to read.");
	}


}*/
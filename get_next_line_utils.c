#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t	strleng;
	size_t	i;
	char	*newstr;

	if (!str)
		return (NULL);
	i = 0;
	strleng = strlen(str);
	newstr = (char *)malloc(strleng + 1);
	if (!newstr)
		return (NULL);
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
#include "ft_string.h"

static char	*str_normalize(char *tmp, int i)
{
	char	*str;

	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
		str[i] = tmp[i];
	return (str);
}

char	*get_line(int fd)
{
	int		i;
	int		r;
	char	tmp[8192];
	char	*str;
	char	c;

	i = 0;
	c = '\0';
	while (1)
	{
		r = read(fd, &c, 1);
		if (c == '\n')
			tmp[i++] = c;
		if (r <= 0 || c == '\n' || c == '\0')
			break ;
		tmp[i++] = c;
	}
	if (i < 1 || r <= 0)
		return (NULL);
	str = str_normalize(tmp, i);
	return (str);
}

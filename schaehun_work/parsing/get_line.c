#include "ft_string.h"

char	*get_line(int fd)
{
	int	i;
	char	buf[2];
	char	temp[512];
	char	*line;

	i = -1;
	buf[0] = '0';
	while (buf[0] && buf[0] != '\n')
	{
		if (read(fd, buf, 1) < 0)
			return (NULL);
		if (i > 512)
			return (NULL);
		temp[++i] = buf[0];
	}
	temp[i] = '\0';
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strcpy(line, temp);
	return (line);
}

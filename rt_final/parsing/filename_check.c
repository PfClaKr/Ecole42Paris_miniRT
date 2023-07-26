#include "parse.h"
#include <fcntl.h>

int	filename_check(char *filename)
{
	int	fd;
	int	len;
	int	filename_len;

	if (!filename)
		return (-1);
	len = ft_strlen(filename);
	filename_len = ft_strlen(ft_strrchr(filename, '/'));
	if (len < 4 || filename_len < 4)
		return (-1);
	if (!(filename[len - 3] == '.' && filename[len - 2] == 'r'
			&& filename[len - 1] == 't'))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

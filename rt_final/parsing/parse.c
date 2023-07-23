#include "parse.h"
#include <fcntl.h>

t_list	*parse_object_by_id(char **data)
{
	char	*id;

	if (!data)
		return (NULL);
	id = data[0];
	if (ft_strcmp(id, "A") == 0)
		return (parse_object_a(data));
	else if (ft_strcmp(id, "C") == 0)
		return (parse_object_c(data));
	else if (ft_strcmp(id, "L") == 0)
		return (parse_object_l(data));
	else if (ft_strcmp(id, "pl") == 0)
		return (parse_object_pl(data));
	else if (ft_strcmp(id, "sp") == 0)
		return (parse_object_sp(data));
	else if (ft_strcmp(id, "cy") == 0)
		return (parse_object_cy(data));
	return (NULL);
}

void	parse_object(t_list **objects, char *filename)
{
	int		fd;
	char	**data;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		data = parse_get_data(fd);
		if (ft_list_append(objects, parse_object_by_id(data)) == -1)
			break ;
		free_double_arr(data);
	}
	close(fd);
}

int	parse(t_list **objects, char *filename)
{
	if (data_integrity_check(filename) == -1)
		return (-1);
	parse_object(objects, filename);
	return (0);
}

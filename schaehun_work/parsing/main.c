
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "object_structures.h"
#include "ft_string.h"
#include "utils.h"
#include "parse.h"

int	parse(t_list *objects)
{
	int	fd;
	char	**data;

	if (data_integrity_check("scene.rt") == -1)
		printf("line: %d: data_integrity_check_error\n", __LINE__);


	fd = open("scene.rt", O_RDONLY);
	data = parse_get_data(fd);
	close(fd);
	free_double_arr(data);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_list	objects;
	parse(&objects);

	return (0);
}

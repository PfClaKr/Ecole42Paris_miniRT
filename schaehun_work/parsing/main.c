
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "object_structures.h"
#include "ft_list.h"
#include "ft_string.h"
#include "utils.h"
#include "parse.h"


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
	int	fd;
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
	{
		printf("line: %d: data_integrity_check_error\n", __LINE__);
		return (-1);
	}
	parse_object(objects, filename);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*objects;
	if (parse(&objects, "scene.rt") == -1)
	{
		printf("parse error\n");
		return (1);
	}

	printf("a : %f\n", ((t_ambient_light *)(objects->data))->ratio);
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->color.x);
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->color.y);
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->color.z);
	
	printf("\n");
	t_list *node;
	node = objects;
	while (node->next)
		node = node->next;

	printf("cy : %f\n", ((t_cylinder *)(node->data))->pos.x);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->orivec.x);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->diameter);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->height);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->color.x);
	
	ft_list_destroy(&objects, &free);

	return (0);
}

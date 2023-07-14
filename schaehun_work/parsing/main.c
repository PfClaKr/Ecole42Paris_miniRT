
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "ft_string.h"
#include "utils.h"
#include "object_structures.h"

char	**parse_get_data(int fd)
{
	char	*line;
	char	**data;

	line = tab_to_space(get_line(fd));
	data = ft_split(line, ' ');
	free(line);
	return (data);
}

int	parse_get_object_id(char *id)
{
	if (ft_strcmp(id, "A") == 0)
		return (1);
	if (ft_strcmp(id, "C") == 0)
		return (2);
	if (ft_strcmp(id, "L") == 0)
		return (3);
	if (ft_strcmp(id, "sp") == 0)
		return (4);
	if (ft_strcmp(id, "pl") == 0)
		return (5);
	if (ft_strcmp(id, "cy") == 0)
		return (6);
	return (0);
}

int	data_get_count(char **data)
{
	int	i;
	
	i = 0;
	while (data[i])
		i++;
	return (i);
}

double	*data_get_color(char **data, int n)
{
	char	**rgb;
	double	*color;

	rgb = ft_split(data[n], ',');
	if (!rgb)
		return (NULL);
	if (data_get_count(rgb) != 3)
		return (NULL);
	color = malloc(sizeof(double) * 3);
	if (!color)
		return (NULL);
	color[0] = ft_atof(rgb[0]);
	color[1] = ft_atof(rgb[1]);
	color[2] = ft_atof(rgb[2]);
	free_double_arr(rgb);
	return (color);
}

int	parse_object_a(t_list objects, char **data)
{
	double	ratio;
	double	**color;
	char	**rgb;
	t_ambient_light	a;

	ratio = data_get_ratio(data, 1);
	color = data_get_color(data, 2);
	if (data_get_count(data) != 3 && data_integrity_check_a(ratio, color) == -1)
		return (-1);
	return (0);
}

int	parse_object(t_list objects, char **data)
{
	int	id;
	id = parse_get_object_id(data[0]);
	if (id == 0)
		return (-1);
	if (id == 1)
		if (parse_object_a(objects, data) == -1)
			return (-1);
	if (id == 2)
		if (parse_object_c(objects, data) == -1)
			return (-1);
	if (id == 3)
		if (parse_object_l(objects, data) == -1)
			return (-1);
	if (id == 4)
		if (parse_object_sp(objects, data) == -1)
			return (-1);
	if (id == 5)
		if (parse_object_pl(objects, data) == -1)
			return (-1);
	if (id == 6)
		if (parse_object_cy(objects, data) == -1)
			return (-1);
	return (0);
}

int	parse(t_list *objects)
{
	int	fd;
	char	**data;
	t_list	obj;

	fd = open("scene.rt", O_RDONLY);

	data = parse_get_data(fd);
	if (parse_object(objects, data) == -1)
		return (-1);
	// if (parse_obj(&obj, data) < 0)
	// 	return (-2);
	// list_append(objects, &obj);
	free_double_arr(data);




//	parse_check_id();
//	parse_get_id();
//	
//	parse_check_pos();
//	parse_get_pos();
//	parse_check_rgb();
//	parse_get_rgb();
//	parse_check_angle();
//	parse_get_angle();
	
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_list	objects;
	parse(&objects);

	return (0);
}

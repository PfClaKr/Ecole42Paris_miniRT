#include "parse.h"

double	data_get_ratio(char *data)
{
	return (ft_atof(data));
}

t_vec3	data_get_color(char *data)
{
	char		**tmp;
	t_vec3		color;

	tmp = ft_split(data, ',');
	if (!tmp)
	{
		color.x = 0;
		color.y = 0;
		color.z = 0;
		return (color);
	}
	color.x = ft_atoi(tmp[0]);
	color.y = ft_atoi(tmp[1]);
	color.z = ft_atoi(tmp[2]);
	free_double_arr(tmp);
	return (color);
}

t_vec3	data_get_pos(char *data)
{
	char		**tmp;
	t_vec3		pos;

	tmp = ft_split(data, ',');
	if (!tmp)
	{
		pos.x = 0;
		pos.y = 0;
		pos.z = 0;
		return (pos);
	}
	pos.x = ft_atof(tmp[0]);
	pos.y = ft_atof(tmp[1]);
	pos.z = ft_atof(tmp[2]);
	free_double_arr(tmp);
	return (pos);
}
#include "parse.h"

int	data_check_ratio(char *data)
{
	double	ratio;

	if (!ft_isdouble(data))
		return (-1);
	ratio = ft_atof(data);
	if (ratio < 0.0 || ratio > 1.0)
		return (-1);
	return (0);
}

int	data_check_color(char *data)
{
	int		color[3];
	char	**tmp;

	tmp = ft_split(data, ',');
	if (!tmp || count_double_arr(tmp) != 3 || ft_cntchar(data, ',') != 2)
		return (free_double_arr(tmp), -1);
	if (!ft_isint(tmp[0]) || !ft_isint(tmp[1]) || !ft_isint(tmp[2]))
		return (free_double_arr(tmp), -1);
	color[0] = ft_atoi(tmp[0]);
	color[1] = ft_atoi(tmp[1]);
	color[2] = ft_atoi(tmp[2]);
	free_double_arr(tmp);
	if ((color[0] < 0 || color[0] > 255)
		|| (color[1] < 0 || color[1] > 255)
		|| (color[2] < 0 || color[2] > 255))
		return (-1);
	return (0);
}

int	data_check_pos(char *data)
{
	int		pos[3];
	char	**tmp;

	tmp = ft_split(data, ',');
	if (!tmp || count_double_arr(tmp) != 3 || ft_cntchar(data, ',') != 2)
		return (free_double_arr(tmp), -1);
	if (!ft_isdouble(tmp[0]) || !ft_isdouble(tmp[1]) || !ft_isdouble(tmp[2]))
		return (free_double_arr(tmp), -1);
	pos[0] = ft_atoi(tmp[0]);
	pos[1] = ft_atoi(tmp[1]);
	pos[2] = ft_atoi(tmp[2]);
	free_double_arr(tmp);
	if ((pos[0] < -1000 || pos[0] > 1000)
		|| (pos[1] < -1000 || pos[1] > 1000)
		|| (pos[2] < -1000 || pos[2] > 1000))
		return (-1);
	return (0);
}

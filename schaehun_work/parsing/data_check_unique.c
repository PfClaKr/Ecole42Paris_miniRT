#include "parse.h"

int	data_check_orivec(char *data)
{
	double	ori[3];
	char	**tmp;

	tmp = ft_split(data, ',');
	if (!tmp || count_double_arr(tmp) != 3 || ft_cntchar(data, ',') != 2)
		return (free_double_arr(tmp), -1);
	if (!ft_isdouble(tmp[0]) || !ft_isdouble(tmp[1]) || !ft_isdouble(tmp[2]))
		return (free_double_arr(tmp), -1);
	ori[0] = ft_atof(tmp[0]);
	ori[1] = ft_atof(tmp[1]);
	ori[2] = ft_atof(tmp[2]);
	free_double_arr(tmp);
	if ((ori[0] < -1.0 || ori[0] > 1.0)
			|| (ori[1] < -1.0 || ori[1] > 1.0)
			|| (ori[2] < -1.0 || ori[2] > 1.0))
		return (-1);
	return (0);
}

int	data_check_fov(char *data)
{
	int	fov;

	if (!ft_isint(data))
		return (-1);
	fov = ft_atoi(data);
	if (fov < 0 || fov > 180)
		return (-1);
	return (0);
}

int	data_check_size(char *data)
{
	double	size;

	if (!ft_isdouble(data))
		return (-1);
	size = ft_atof(data);
	if (size < 0 || size > 1000)
		return (-1);
	return (0);
}


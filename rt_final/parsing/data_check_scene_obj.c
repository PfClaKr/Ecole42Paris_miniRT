#include "parse.h"

int	data_check_a(char **data)
{
	if (count_double_arr(data) != 3)
		return (-1);
	if (data_check_ratio(data[1]) == -1)
		return (-1);
	if (data_check_color(data[2]) == -1)
		return (-1);
	return (1);
}

int	data_check_c(char **data)
{
	if (count_double_arr(data) != 4)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_orivec(data[2]) == -1)
		return (-1);
	if (data_check_fov(data[3]) == -1)
		return (-1);
	return (2);
}

int	data_check_l(char **data)
{
	if (count_double_arr(data) != 4)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_ratio(data[2]) == -1)
		return (-1);
	if (data_check_color(data[3]) == -1)
		return (-1);
	return (3);
}

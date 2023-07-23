#include "parse.h"

int	data_check_pl(char **data)
{
	if (count_double_arr(data) != 4)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_orivec(data[2]) == -1)
		return (-1);
	if (data_check_color(data[3]) == -1)
		return (-1);
	return (4);
}

int	data_check_sp(char **data)
{
	if (count_double_arr(data) != 4)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_size(data[2]) == -1)
		return (-1);
	if (data_check_color(data[3]) == -1)
		return (-1);
	return (5);
}

int	data_check_cy(char **data)
{
	if (count_double_arr(data) != 6)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_orivec(data[2]) == -1)
		return (-1);
	if (data_check_size(data[3]) == -1)
		return (-1);
	if (data_check_size(data[4]) == -1)
		return (-1);
	if (data_check_color(data[5]) == -1)
		return (-1);
	return (6);
}

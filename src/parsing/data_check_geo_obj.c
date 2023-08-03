/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_geo_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:41 by ychun             #+#    #+#             */
/*   Updated: 2023/07/26 14:22:27 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
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
	return (0);
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
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_geo_obj_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:41 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 20:10:28 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	data_check_pl(char **data)
{
	if (count_double_arr(data) < 4)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_orivec(data[2]) == -1)
		return (-1);
	if (data_check_color(data[3]) == -1)
		return (-1);
	if (data_check_texture(&data[4]) == -1)
		return (-1);
	return (0);
}

int	data_check_sp(char **data)
{
	if (count_double_arr(data) < 4)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_size(data[2]) == -1)
		return (-1);
	if (data_check_color(data[3]) == -1)
		return (-1);
	if (data_check_texture(&data[4]) == -1)
		return (-1);
	return (0);
}

int	data_check_cy(char **data)
{
	if (count_double_arr(data) < 6)
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
	if (data_check_texture(&data[6]) == -1)
		return (-1);
	return (0);
}

int	data_check_co(char **data)
{
	if (count_double_arr(data) < 6)
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
	if (data_check_texture(&data[6]) == -1)
		return (-1);
	return (0);
}

int	data_check_cu(char **data)
{
	if (count_double_arr(data) < 5)
		return (-1);
	if (data_check_pos(data[1]) == -1)
		return (-1);
	if (data_check_orivec(data[2]) == -1)
		return (-1);
	if (data_check_size(data[3]) == -1)
		return (-1);
	if (data_check_color(data[4]) == -1)
		return (-1);
	if (data_check_texture(&data[5]) == -1)
		return (-1);
	return (0);
}

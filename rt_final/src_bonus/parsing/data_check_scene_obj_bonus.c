/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_scene_obj_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:45 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:42:28 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	data_check_a(char **data)
{
	if (count_double_arr(data) != 3)
		return (-1);
	if (data_check_ratio(data[1]) == -1)
		return (-1);
	if (data_check_color(data[2]) == -1)
		return (-1);
	return (11);
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
	return (12);
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
	return (0);
}

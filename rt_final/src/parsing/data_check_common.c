/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:00 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 19:20:49 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_vec3		color;
	char		**tmp;

	tmp = ft_split(data, ',');
	if (!tmp || count_double_arr(tmp) != 3 || ft_cntchar(data, ',') != 2)
		return (free_double_arr(tmp), -1);
	if (!ft_isint(tmp[0]) || !ft_isint(tmp[1]) || !ft_isint(tmp[2]))
		return (free_double_arr(tmp), -1);
	color.x = ft_atoi(tmp[0]);
	color.y = ft_atoi(tmp[1]);
	color.z = ft_atoi(tmp[2]);
	free_double_arr(tmp);
	if ((color.x < 0 || color.x > 255)
		|| (color.y < 0 || color.y > 255)
		|| (color.z < 0 || color.z > 255))
		return (-1);
	return (0);
}

int	data_check_pos(char *data)
{
	t_vec3		pos;
	char	**tmp;

	tmp = ft_split(data, ',');
	if (!tmp || count_double_arr(tmp) != 3 || ft_cntchar(data, ',') != 2)
		return (free_double_arr(tmp), -1);
	if (!ft_isdouble(tmp[0]) || !ft_isdouble(tmp[1]) || !ft_isdouble(tmp[2]))
		return (free_double_arr(tmp), -1);
	pos.x = ft_atoi(tmp[0]);
	pos.y = ft_atoi(tmp[1]);
	pos.z = ft_atoi(tmp[2]);
	free_double_arr(tmp);
	if ((pos.x < -1000 || pos.x > 1000)
		|| (pos.y < -1000 || pos.y > 1000)
		|| (pos.z < -1000 || pos.z > 1000))
		return (-1);
	return (0);
}

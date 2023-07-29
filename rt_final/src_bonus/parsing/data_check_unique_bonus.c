/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_unique_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:03 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:42:32 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	data_check_orivec(char *data)
{
	t_vec3		ori;
	char		**tmp;

	tmp = ft_split(data, ',');
	if (!tmp || count_double_arr(tmp) != 3 || ft_cntchar(data, ',') != 2)
		return (free_double_arr(tmp), -1);
	if (!ft_isdouble(tmp[0]) || !ft_isdouble(tmp[1]) || !ft_isdouble(tmp[2]))
		return (free_double_arr(tmp), -1);
	ori.x = ft_atof(tmp[0]);
	ori.y = ft_atof(tmp[1]);
	ori.z = ft_atof(tmp[2]);
	free_double_arr(tmp);
	if (vlength(ori) == 0)
		return (-1);
	if ((ori.x < -1.0 || ori.x > 1.0)
		|| (ori.y < -1.0 || ori.y > 1.0)
		|| (ori.z < -1.0 || ori.z > 1.0))
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

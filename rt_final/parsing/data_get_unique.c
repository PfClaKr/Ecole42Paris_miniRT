/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get_unique.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:28 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 03:26:03 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vec3	data_get_orivec(char *data)
{
	char		**tmp;
	t_vec3		orivec;

	tmp = ft_split(data, ',');
	if (!tmp)
	{
		orivec.x = 0;
		orivec.y = 0;
		orivec.z = 0;
		return (orivec);
	}
	orivec.x = ft_atof(tmp[0]);
	orivec.y = ft_atof(tmp[1]);
	orivec.z = ft_atof(tmp[2]);
	orivec = vunit(orivec);
	free_double_arr(tmp);
	return (orivec);
}

double	data_get_fov(char *data)
{
	return (ft_atof(data));
}

double	data_get_size(char *data)
{
	return (ft_atof(data));
}

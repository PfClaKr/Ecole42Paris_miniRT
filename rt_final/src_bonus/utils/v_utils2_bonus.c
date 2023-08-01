/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:33:07 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 05:22:34 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	vset(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

double	vlength2(t_vec3 v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

double	vlength(t_vec3 v)
{
	return (sqrt(vlength2(v)));
}

int	is_vec_equal(t_vec3 v1, t_vec3 v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (1);
	return (0);
}

t_vec3	vup(t_vec3 v)
{
	if (is_vec_equal(v, vec3(0, 1, 0)))
		return (vec3(0, 0, 1));
	if (is_vec_equal(v, vec3(0, -1, 0)))
		return (vec3(0, 0, -1));
	return (vec3(0, 1, 0));
}

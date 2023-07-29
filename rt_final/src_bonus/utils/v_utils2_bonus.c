/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:33:07 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:47:44 by ychun            ###   ########.fr       */
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

t_vec3	vplus(t_vec3 v, t_vec3 v2)
{
	v.x += v2.x;
	v.y += v2.y;
	v.z += v2.z;
	return (v);
}

t_vec3	vplus_(t_vec3 v, double x, double y, double z)
{
	v.x += x;
	v.y += y;
	v.z += z;
	return (v);
}

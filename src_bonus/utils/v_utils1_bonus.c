/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:29:55 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:47:40 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	vdot(t_vec3 v1, t_vec3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vec3	vcross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	tmp;

	tmp.x = (v1.y * v2.z) - (v1.z * v2.y);
	tmp.y = (v1.z * v2.x) - (v1.x * v2.z);
	tmp.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (tmp);
}

// if len is 0, its unexists unit vector.
t_vec3	vunit(t_vec3 v)
{
	double	len;

	len = vlength(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}

t_vec3	vmin(t_vec3 v1, t_vec3 v2)
{
	if (v1.x > v2.x)
		v1.x = v2.x;
	if (v1.y > v2.y)
		v1.y = v2.y;
	if (v1.z > v2.z)
		v1.z = v2.z;
	return (v1);
}

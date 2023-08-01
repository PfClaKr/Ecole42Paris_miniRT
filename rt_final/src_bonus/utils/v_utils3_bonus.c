/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:37:09 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 05:20:18 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_vec3	vplus(t_vec3 v, t_vec3 v2)
{
	v.x += v2.x;
	v.y += v2.y;
	v.z += v2.z;
	return (v);
}

t_vec3	vminus(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3	vmult(t_vec3 v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

t_vec3	vmult_(t_vec3 v1, t_vec3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec3	vdivide(t_vec3 v, double t)
{
	v.x *= 1 / t;
	v.y *= 1 / t;
	v.z *= 1 / t;
	return (v);
}

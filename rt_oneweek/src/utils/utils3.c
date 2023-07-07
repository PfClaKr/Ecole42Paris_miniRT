/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:37:09 by ychun             #+#    #+#             */
/*   Updated: 2023/06/05 00:49:31 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT_utils.h"

t_vec3	vminus(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3	vminus_(t_vec3 v, double x, double y, double z)
{
	v.x -= x;
	v.y -= y;
	v.z -= z;
	return (v);
}

// 벡터 * 스칼라 곱연산
t_vec3	vmult(t_vec3 v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

// 벡터 끼리 곱연산
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

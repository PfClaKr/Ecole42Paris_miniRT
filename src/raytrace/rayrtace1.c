/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayrtace1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:07:08 by ychun             #+#    #+#             */
/*   Updated: 2023/06/05 02:09:20 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	r;

	r.orig = orig;
	r.dir = vunit(dir);
	return (r);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	p;

	p = vplus(ray->orig, vmult(ray->dir, t));
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:01:06 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 21:21:28 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	hit_plane(t_plane *obj, t_ray ray, t_hit_record *rec)
{
	double	numerator;
	double	denominator;
	double	root;

	denominator = vdot(ray.orivec, obj->orivec);
	numerator = vdot(vminus(obj->pos, ray.pos), obj->orivec);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, root));
	rec->normal = obj->orivec;
	rec->color = obj->color;
	set_face_normal(ray, rec);
	return (1);
}
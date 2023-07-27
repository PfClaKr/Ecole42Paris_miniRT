/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:01:06 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 03:11:26 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	hit_plane(t_plane *data, t_ray ray, t_hit_record *rec)
{
	float	numerator;
	float	denominator;
	float	root;

	denominator = vdot(ray.orivec, data->orivec);
	if (fabs(denominator) < EPSILON)
		return (0);
//	printf("denominator : %f\n", denominator);
	numerator = vdot(vminus(data->pos, ray.pos), data->orivec);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, root));
	rec->normal = data->orivec;
	rec->color = data->color;
	set_face_normal(ray, rec);
	return (1);
}

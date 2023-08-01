/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:01:06 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 17:56:22 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

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
	set_face_normal(ray, rec);
	get_plane_uv_value(rec);
	set_obj_color(obj->xpm_img, rec, obj->color);
	return (1);
}

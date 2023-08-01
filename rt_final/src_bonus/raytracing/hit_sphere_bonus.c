/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:33:55 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 17:55:41 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	hit_sphere(t_sphere *obj, t_ray ray, t_hit_record *rec)
{
	t_hit_num	num;

	num.oc = vminus(ray.pos, obj->pos);
	num.a = vlength2(ray.orivec);
	num.half_b = vdot(num.oc, ray.orivec);
	num.discriminant = (num.half_b * num.half_b)
		- (num.a * (vlength2(num.oc) - obj->radius2));
	if (num.discriminant < 0)
		return (0);
	num.root = (-num.half_b - sqrt(num.discriminant)) / num.a;
	if (num.root < rec->tmin || rec->tmax < num.root)
	{
		num.root = (-num.half_b + sqrt(num.discriminant)) / num.a;
		if (num.root < rec->tmin || rec->tmax < num.root)
			return (0);
	}
	rec->t = num.root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, num.root));
	rec->normal = vdivide(vminus(rec->p, obj->pos), obj->radius);
	get_sphere_uv_value(rec);
	set_obj_color(obj->xpm_img, rec, obj->color);
	set_face_normal(ray, rec);
	return (1);
}

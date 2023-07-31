/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_corn_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 02:05:33 by ychun             #+#    #+#             */
/*   Updated: 2023/07/31 14:54:10 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	get_corn_normal(t_cylinder *obj, t_hit_record *rec, t_vec3 p, double r)
{
	double	hit_height;
	double	max_height;
	t_vec3	hit_normal;
	t_vec3	hit_pos;

	hit_height = vdot(vminus(p, obj->pos), obj->orivec);
	max_height = obj->height;
	if (hit_height > max_height)
		return (0);
	hit_pos = vplus(obj->pos, vmult(obj->orivec, hit_height));
	hit_normal = vunit(vminus(p, hit_pos));
	rec->normal = vunit(vplus(vmult(obj->orivec, r),
				vmult(hit_normal, (max_height - hit_height))));
	rec->color = obj->color;
	return (1);
}

int	hit_corn_side(t_cylinder *obj, t_ray ray, t_hit_record *rec)
{
	t_hit_num	num;
	double		r;

	num.p = vminus(ray.pos, obj->pos);
	r = ((obj->diameter / 2 * (obj->height - vdot(vminus(num.p, obj->pos),
						obj->orivec))) / obj->height);
	num.a = vlength2(vcross(ray.orivec, obj->orivec));
	num.half_b = vdot(vcross(ray.orivec, obj->orivec),
			vcross(num.p, obj->orivec));
	num.c = vlength2(vcross(num.p, obj->orivec)) - pow(r, 2);
	num.discriminant = num.half_b * num.half_b - num.a * num.c;
	if (num.discriminant < 0)
		return (0);
	num.root = (-num.half_b - sqrt(num.discriminant)) / num.a;
	if (num.root < rec->tmin || rec->tmax < num.root)
	{
		num.root = (-num.half_b + sqrt(num.discriminant)) / num.a;
		if (num.root < rec->tmin || rec->tmax < num.root)
			return (0);
	}
	if (!get_corn_normal(obj, rec, num.p, r))
		return (0);
	rec->p = vplus(ray.pos, vmult(ray.orivec, num.root));
	set_face_normal(ray, rec);
	return (1);
}

int	hit_corn(t_cylinder *obj, t_ray ray, t_hit_record *rec)
{
	int	ret;

	ret = 0;
	ret += hit_corn_side(obj, ray, rec);
//	ret += hit_corn_bottom(obj, ray, rec);
	return (ret);
}

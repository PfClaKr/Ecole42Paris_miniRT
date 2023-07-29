/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:17:27 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:43:37 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	get_cy_normal(t_cylinder *obj, t_hit_record *rec, t_vec3 p)
{
	double	hit_height;
	double	max_height;
	t_vec3	hit_pos;

	hit_height = vdot(vminus(p, obj->pos), obj->orivec);
	max_height = obj->height / 2;
	if (fabs(hit_height) > max_height)
		return (0);
	hit_pos = vplus(obj->pos, vmult(obj->orivec, hit_height));
	rec->normal = vunit(vminus(p, hit_pos));
	return (1);
}

int	hit_cy_side(t_cylinder *obj, t_ray ray, t_hit_record *rec)
{
	t_hit_num	num;

	num.p = vminus(ray.pos, obj->pos);
	num.a = vlength2(vcross(ray.orivec, obj->orivec));
	num.half_b = vdot(vcross(ray.orivec, obj->orivec),
			vcross(num.p, obj->orivec));
	num.c = vlength2(vcross(num.p, obj->orivec)) - pow(obj->diameter / 2, 2);
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
	if (!get_cy_normal(obj, rec, vplus(ray.pos, vmult(ray.orivec, num.root))))
		return (0);
	rec->p = vplus(ray.pos, vmult(ray.orivec, num.root));
	rec->t = num.root;
	rec->color = obj->color;
	set_face_normal(ray, rec);
	return (1);
}

int	hit_cy_cap(t_cylinder *obj, t_ray ray, t_hit_record *rec, double h)
{
	double	r;
	double	root;
	t_vec3	cap_center;

	r = obj->diameter / 2;
	cap_center = vplus(obj->pos, vmult(obj->orivec, h));
	root = vdot(vminus(cap_center, ray.pos), obj->orivec)
		/ vdot(ray.orivec, obj->orivec);
	if (fabs(r) < fabs(vlength(vminus(cap_center,
					vplus(ray.pos, vmult(ray.orivec, root))))))
		return (0);
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, root));
	rec->tmax = rec->t;
	if (0 < h)
		rec->normal = obj->orivec;
	else
		rec->normal = vmult(obj->orivec, -1);
	set_face_normal(ray, rec);
	rec->color = obj->color;
	return (1);
}

int	hit_cylinder(t_cylinder *obj, t_ray ray, t_hit_record *rec)
{
	int	ret;

	ret = 0;
	ret += hit_cy_cap(obj, ray, rec, (obj->height) / 2);
	ret += hit_cy_cap(obj, ray, rec, -(obj->height / 2));
	ret += hit_cy_side(obj, ray, rec);
	return (ret);
}

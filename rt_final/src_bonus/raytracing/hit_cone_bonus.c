/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:59:41 by ychun             #+#    #+#             */
/*   Updated: 2023/08/02 00:19:40 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

static int	get_cone_normal(t_cone *obj, t_ray ray,
	t_hit_record *rec, t_hit_num num)
{
	double	p_height;
	t_vec3	p;

	p = vplus(ray.pos, vmult(ray.orivec, num.root));
	p_height = vdot(vminus(p, obj->pos), obj->orivec);
	if (p_height < 0 || p_height > obj->height)
		return (0);
	p_height -= obj->height;
	rec->normal = vunit(vminus(p, vplus(obj->pos, vmult(obj->orivec,
						vdot(vminus(p, obj->pos), obj->orivec)))));
	rec->normal = vunit(vplus(vmult(obj->orivec, (obj->diameter / 2 * p_height)
					/ obj->height), vmult(rec->normal, p_height)));
	rec->p = p;
	rec->t = num.root;
	set_face_normal(ray, rec);
	//get_cone_uv_value(obj, rec);
	//set_obj_color(obj, rec);
	return (1);
}

static int	hit_cone_side(t_cone *obj, t_ray ray, t_hit_record *rec)
{
	t_hit_num	num;

	num.h_ratio = pow(obj->diameter / 2, 2) / pow(obj->height, 2);
	num.oc = vminus(ray.pos, obj->pos);
	num.a = vdot(ray.orivec, ray.orivec) - vdot(ray.orivec, obj->orivec)
		* vdot(ray.orivec, obj->orivec) * (1 + num.h_ratio);
	num.half_b = vdot(ray.orivec, num.oc) - vdot(num.oc, obj->orivec)
		* vdot(ray.orivec, obj->orivec) * (1 + num.h_ratio) + num.h_ratio
		* obj->height * vdot(ray.orivec, obj->orivec);
	num.c = vdot(num.oc, num.oc) - vdot(num.oc, obj->orivec) * vdot(num.oc,
			obj->orivec) * (1 + num.h_ratio) - pow(obj->diameter / 2, 2)
		+ 2 * num.h_ratio * obj->height * vdot(num.oc, obj->orivec);
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
	if (!get_cone_normal(obj, ray, rec, num))
		return (0);
	return (1);
}

int	hit_cone(t_cone *obj, t_ray ray, t_hit_record *rec)
{
	int	ret;

	ret = 0;
//	ret += hit_cone_cap(obj, ray, rec);
	ret += hit_cone_side(obj, ray, rec);
	return (ret);
}

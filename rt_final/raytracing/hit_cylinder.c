/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:48:31 by ychun             #+#    #+#             */
/*   Updated: 2023/07/26 16:09:00ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	get_cy_normal(t_cylinder *data, t_hit_record *rec)
{
	double	hit_height;
	double	max_height;
	t_vec3	hit_pos;
	t_vec3	ret;

	hit_height = vdot(vminus(rec->p, data->pos), data->orivec);
	max_height = data->height / 2;
	if (fabs(hit_height) > max_height)
		return (0);
	hit_pos = vplus(data->pos, vmult(data->orivec, hit_height));
	ret = vunit(vminus(rec->p, hit_pos));
	rec->normal = ret;
	return (1);
}

int	hit_cy_side(t_cylinder *data, t_ray ray, t_hit_record *rec)
{
	t_hit_num	num;

	num.p = vminus(ray.pos, data->pos);
	num.a = vlength2(vcross(ray.orivec, data->orivec));
	num.half_b = vdot(vcross(ray.orivec, data->orivec),
			vcross(num.p, data->orivec));
	num.c = vlength2(vcross(num.p, data->orivec)) - pow(data->diameter / 2, 2);
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
	rec->t = num.root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, num.root));
	if (!get_cy_normal(data, rec))
		return (0);
	rec->albedo = vec3(ALBEDO_R, ALBEDO_G, ALBEDO_B);
	rec->color = data->color;
	set_face_normal(ray, rec);
	return (1);
}

int	hit_cy_cap(t_cylinder *data, t_ray ray, t_hit_record *rec, double h)
{
	double	r;
	double	root;
	t_vec3	cap_center;

	r = data->diameter / 2;
	cap_center = vplus(data->pos, vmult(data->orivec, h));
	root = vdot(vminus(cap_center, ray.pos), data->orivec)
		/ vdot(ray.orivec, data->orivec);
	if (fabs(r) < fabs(vlength(vminus(cap_center,
					vplus(ray.pos, vmult(ray.orivec, root))))))
		return (0);
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, root));
	rec->tmax = rec->t;
	if (0 < h)
		rec->normal = data->orivec;
	else
		rec->normal = vmult(data->orivec, -1);
	set_face_normal(ray, rec);
	rec->color = data->color;
	return (1);
}

int	hit_cylinder(t_cylinder *data, t_ray ray, t_hit_record *rec)
{
	int	ret;

	ret = 0;
	ret += hit_cy_cap(data, ray, rec, data->height / 2);
	ret += hit_cy_cap(data, ray, rec, -(data->height / 2));
	ret += hit_cy_side(data, ray, rec);
	return (ret);
}

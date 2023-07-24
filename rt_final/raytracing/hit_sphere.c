/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:33:55 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:45:34 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

//카메라가 구안에 있을때 법선 반대로
static void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.orivec, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

int	hit_sphere(t_sphere *data, t_ray ray, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	discriminant;
	double	root;

	oc = vminus(ray.pos, data->pos);
	a = vlength2(ray.orivec);
	half_b = vdot(oc, ray.orivec);
	discriminant = (half_b * half_b) - (a * (vlength2(oc) - data->radius2));
	if (discriminant < 0)
		return (0);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	rec->t = root;
	rec->p = vplus(ray.pos, vmult(ray.orivec, root));
	rec->normal = vdivide(vminus(rec->p, data->pos), data->radius);
	rec->albedo = vec3(ALBEDO_R, ALBEDO_G, ALBEDO_B);
	set_face_normal(ray, rec);
	return (1);
}

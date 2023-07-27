/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_model_phong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:11:13 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 23:19:48 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static int	phong_model_shadow(t_list *objects,
	t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = light_len;
	if (hit_object(objects, light_ray, &rec))
		return (1);
	return (0);
}

static t_vec3	phong_model_specular(t_light *obj, t_ray camera_ray,
	t_hit_record *rec, t_ray light_ray)
{
	t_vec3	view_dir;
	t_vec3	rev_vec;
	t_vec3	reflect_dir;
	t_vec3	specular;

	view_dir = vunit(vmult(camera_ray.orivec, -1));
	rev_vec = vmult(light_ray.orivec, -1);
	reflect_dir = vminus(rev_vec,
			vmult(rec->normal, vdot(rev_vec, rec->normal) * 2));
	specular = vmult(vmult(obj->color, SPECULAR_STRENGTH),
			pow(fmax(vdot(view_dir, reflect_dir), 0.0), SHININESS_VALUE));
	return (specular);
}

static t_vec3	phong_model_diffuse(t_light *obj,
	t_hit_record *rec, t_ray light_ray)
{
	double	diffuse_strength;
	t_vec3	diffuse_color;

	diffuse_strength = fmax(vdot(rec->normal, light_ray.orivec), 0.0);
	diffuse_color = vmult(obj->color, diffuse_strength);
	return (diffuse_color);
}

t_vec3	phong_model(t_list *objects, t_ray camera_ray,
	t_hit_record *rec, t_ambient_light *amblight)
{
	t_ray	light_ray;
	double	light_len;
	t_vec3	diffuse;
	t_vec3	specular;
	t_light	*obj;

	obj = (t_light *)ft_list_find(objects, L);
	light_ray = init_light_ray(obj, rec);
	light_len = (vlength(vminus(obj->pos, rec->p)));
	if (phong_model_shadow(objects, light_ray, light_len))
		return (vec3(0, 0, 0));
	diffuse = phong_model_diffuse(obj, rec, light_ray);
	specular = phong_model_specular(obj, camera_ray, rec, light_ray);
	return (vmult(vplus(vplus(amblight->color, diffuse), specular),
			obj->ratio));
}

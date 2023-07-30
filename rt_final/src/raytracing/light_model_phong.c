/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_model_phong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:31:52 by ychun             #+#    #+#             */
/*   Updated: 2023/07/30 22:33:57 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static int	phong_model_shadow(t_list *objects, t_light *obj, t_hit_record *rec)
{
	t_hit_record	temp_rec;
	t_ray			ray;
	double			light_len;

	light_len = vlength(vminus(obj->pos, rec->p));
	temp_rec.tmin = EPSILON;
	temp_rec.tmax = light_len;
	ray.pos = rec->p;
	ray.orivec = vunit(vmult(vminus(obj->pos, rec->p), 1));
	if (hit_object(objects, ray, &temp_rec))
		return (1);
	return (0);
}

static t_vec3	phong_model_diffuse(t_light *obj,
	t_hit_record *rec, t_ray light_ray)
{
	double	diffuse_strength;
	t_vec3	diffuse_color;
	double	light_len;
	double	light_len_ratio;

	light_len = vlength(vminus(obj->pos, rec->p));
	light_len_ratio = fmax(1 - (light_len
				/ (obj->ratio * LIGHT_STRENGTH)), 0.0);
	diffuse_strength = fmax(vdot(rec->normal, light_ray.orivec), 0.0);
	diffuse_strength = pow(diffuse_strength, LIGHT_SHARPNESS);
	diffuse_color = vdivide(obj->color, 255);
	diffuse_color = vmult(diffuse_color, obj->ratio);
	diffuse_color = vmult(diffuse_color, diffuse_strength);
	diffuse_color = vmult_(diffuse_color, rec->color);
	diffuse_color = vmult(diffuse_color, light_len_ratio);
	return (diffuse_color);
}

t_vec3	phong_model(t_list *objects, t_light *obj, t_hit_record *rec)
{
	t_ray	light_ray;
	t_vec3	light_color;

	light_ray = init_light_ray(obj, rec);
	if (phong_model_shadow(objects, obj, rec))
		return (vec3(0, 0, 0));
	light_color = phong_model_diffuse(obj, rec, light_ray);
	light_color = vmult_(light_color, vec3(ALBEDO_R, ALBEDO_G, ALBEDO_B));
	return (light_color);
}

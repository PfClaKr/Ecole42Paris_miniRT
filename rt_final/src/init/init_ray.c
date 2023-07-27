/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:40:02 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 23:09:38 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_ray	init_light_ray(t_light *obj, t_hit_record *rec)
{
	t_ray	ray;
	t_vec3	light_dir;

	light_dir = vminus(obj->pos, rec->p);
	ray.pos = vplus(rec->p, vmult(rec->normal, EPSILON));
	ray.orivec = vunit(light_dir);
	return (ray);
}

t_ray	init_camera_ray(t_camera *obj, int u, int v)
{
	t_ray	ray;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	temp_orivec;

	ray.pos = obj->pos;
	horizontal = vmult(obj->right_normal, (double)u);
	vertical = vmult(obj->up_normal, (double)v);
	temp_orivec = vplus(obj->left_bottom, horizontal);
	temp_orivec = vplus(temp_orivec, vertical);
	ray.orivec = vunit(vminus(temp_orivec, ray.pos));
	return (ray);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:21:10 by ychun             #+#    #+#             */
/*   Updated: 2023/07/28 03:49:02 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

//changed ray to camera_ray
t_vec3	light_model(t_list *objects, t_ray camera_ray, t_hit_record *rec)
{
	t_vec3			light_color;
	t_ambient_light	*amblight;
	t_vec3			amblight_color;
	t_list			*temp;

	temp = objects;
	amblight = (t_ambient_light *)ft_list_find(objects, A);
	amblight_color = amblight->color;
	while (temp)
	{
		if (temp->id == L)
			light_color = phong_model(objects, camera_ray, rec);
		temp = temp->next;
	}
	amblight_color = vdivide(amblight_color, 255);
	amblight_color = vmult(amblight_color, amblight->ratio);
	amblight_color = vmult_(amblight_color, rec->color);
	light_color = vplus(light_color, amblight_color);
	return (light_color);
}

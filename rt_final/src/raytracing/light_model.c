/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:21:10 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 23:18:58 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

//changed ray to camera_ray
t_vec3	light_model(t_list *objects, t_ray camera_ray, t_hit_record *rec)
{
	t_vec3			light_color;
	t_ambient_light	*temp_amblight;
	t_list			*temp;

	temp = objects;
	temp_amblight = (t_ambient_light *)ft_list_find(objects, A);
	while (temp)
	{
		if (temp->id == L)
			light_color = phong_model(objects, camera_ray,
					rec, temp_amblight);
		temp = temp->next;
	}
	return (light_color);
}

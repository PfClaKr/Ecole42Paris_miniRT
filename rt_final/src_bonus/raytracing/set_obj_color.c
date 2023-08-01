/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 05:32:45 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 17:58:58 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

t_vec3	set_color_checker(double u, double v)
{
	int	temp_u;
	int	temp_v;

	temp_u = floor(u * CHECKBOARD_WIDTH);
	temp_v = floor(v * CHECKBOARD_HEIGHT);
	if ((temp_u + temp_v) % 2)
		return (vec3(0, 0, 0));
	else
		return (vec3(255, 255, 255));
}

void	set_obj_color(t_xpm_img *xpm_img, t_hit_record *rec, t_vec3	obj_color)
{
	if (!xpm_img->checkerboard)
		rec->color = set_color_checker(rec->u, rec->v);
	else if (!xpm_img->texture)
	{
		rec->color = set_color_mapping(rec->u, rec->v, xpm_img->texture);
		if (!xpm_img->bump)
			rec->normal = set_normal_mapping(rec, xpm_img->bump);
	}
	else
		rec->color = obj_color;
}

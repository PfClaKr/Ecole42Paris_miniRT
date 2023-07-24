/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:54:27 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:56:27 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static int	hit_object(t_list *obj, t_ray ray, t_hit_record *rec)
{
	int	hit;

	hit = 0;
	while (obj)
	{
		if (obj->id == SP)
			hit = hit_sphere(obj->data, ray, rec);
//		else if (obj->id == CY)
//			hit = hit_cylinder(obj->data, ray, rec);
//		else if (obj->id == PL)
//			hit = hit_plane(obj->data, ray, rec);
		if (hit > 0)
			rec->tmax = rec->t;
		obj = obj->next;
	}
	return (hit);
}

static t_vec3	ray_color(t_list *obj, t_ray ray, t_ambient_light *amblight)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	if (hit_object(obj, ray, &rec))
		return (vec3(1, 0, 0));
//		return (lighting_model(obj, &rec));
	return (vmult(amblight->color, amblight->ratio));
}

void	raytracing(t_list *obj, t_mlx *mlx)
{
	int			i;
	int			j;
	t_ray		ray;
	t_camera	*temp_cam;
	t_ambient_light	*temp_amblight;	
	t_vec3		color;

	temp_cam = (t_camera *)ft_list_find(obj, C);
	temp_amblight = (t_ambient_light *)ft_list_find(obj, A);
	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray = init_ray(temp_cam, i, j);
			color = ray_color(obj, ray, temp_amblight);
			mlx_pixel_put_img(mlx, i, j, get_color(color));
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
}

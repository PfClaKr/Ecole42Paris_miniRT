/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:54:27 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 14:51:23 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

int	hit_object(t_list *obj, t_ray ray, t_hit_record *rec)
{
	int	hit;

	hit = 0;
	while (obj)
	{
		if (obj->id == SP)
			hit += hit_sphere(obj->data, ray, rec);
		else if (obj->id == CY)
			hit += hit_cylinder(obj->data, ray, rec);
		else if (obj->id == PL)
			hit += hit_plane(obj->data, ray, rec);
		if (hit > 0)
			rec->tmax = rec->t;
		obj = obj->next;
	}
	return (hit);
}

static t_vec3	ray_color(t_list *obj, t_ray ray)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	if (hit_object(obj, ray, &rec))
		return (light_model(obj, ray, &rec));
	return (vec3(0, 0, 0));
}

void	rendering(t_mlx *mlx, int i, int j, double color)
{
	if (RENDER_BY_PIXEL)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, color);
	else
		mlx_pixel_put_img(mlx, i, j, color);
}

void	raytracing(t_list *obj, t_mlx *mlx)
{
	int				i;
	int				j;
	t_camera		*temp_cam;
	t_ray			ray;

	temp_cam = (t_camera *)ft_list_find(obj, C);
	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray = init_camera_ray(temp_cam, i, j);
			rendering(mlx, i, HEIGHT - 1 - j,
				get_color(ray_color(obj, ray)));
			++i;
		}
		--j;
	}
	if (!RENDER_BY_PIXEL)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
}

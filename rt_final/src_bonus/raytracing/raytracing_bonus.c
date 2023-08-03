/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:54:27 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 03:06:12 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

int	hit_object(t_list *objects, t_ray ray, t_hit_record *rec)
{
	int	hit;

	hit = 0;
	while (objects)
	{
		if (objects->id == SP)
			hit += hit_sphere(objects->data, ray, rec);
		else if (objects->id == CY)
			hit += hit_cylinder(objects->data, ray, rec);
		else if (objects->id == PL)
			hit += hit_plane(objects->data, ray, rec);
		else if (objects->id == CO)
			hit += hit_cone(objects->data, ray, rec);
//		else if (objects->id == CU)
//			hit += hit_cube(objects->data, ray, rec);
		if (hit > 0)
			rec->tmax = rec->t;
		objects = objects->next;
	}
	return (hit);
}

static t_vec3	ray_color(t_list *objects, t_ray ray)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	if (hit_object(objects, ray, &rec))
		return (light_model(objects, ray, &rec));
	return (vec3(0, 0, 0));
}

void	rendering(t_mlx *mlx, int i, int j, double color)
{
	printf("\rOn the way... %d %%", (j + 1) * 100 / HEIGHT);
	if (RENDER_BY_PIXEL)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, color);
	else
		mlx_pixel_put_img(mlx, i, j, color);
}

void	raytracing_loop(t_list *objects, t_mlx *mlx, int x, int y)
{
	t_ray		ray;
	t_camera	*temp_cam;
	t_vec3		final_color;
	int			i;
	int			anti;

	temp_cam = (t_camera *)ft_list_find(objects, C);
	final_color = vec3(0, 0, 0);
	i = ANTI_ALIASING;
	anti = ANTI_ALIASING;
	if (anti < 1)
		anti = 1;
	while (i >= 0)
	{
		ray = init_camera_ray(temp_cam,
				ft_clamp_int((x + (get_rand_num(ANTI_ALIASING) % 2)),
					0, WIDTH),
				ft_clamp_int((y - (get_rand_num(ANTI_ALIASING) % 2)),
					0, HEIGHT - 1));
		final_color = vplus(final_color, ray_color(objects, ray));
		i--;
	}
	final_color = vdivide(final_color, anti);
	rendering(mlx, x, HEIGHT - 1 - y, get_color(final_color));
}

void	raytracing(t_list *objects, t_mlx *mlx)
{
	int	x;
	int	y;

	y = HEIGHT;
	while (--y >= 0)
	{
		x = -1;
		while (++x < WIDTH)
			raytracing_loop(objects, mlx, x, y);
	}
	if (!RENDER_BY_PIXEL)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
	printf("\nDone!\n");
}

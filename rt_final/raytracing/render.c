/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:54:27 by ychun             #+#    #+#             */
/*   Updated: 2023/07/23 23:33:44 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

t_camera	*obj_find_cam(t_list *obj)
{
	while (obj)
	{
		if (obj->id == C)
			return ((t_camera *)obj->data);
		obj = obj->next;
	}
	return (NULL);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	vp_point;

	ray.pos = cam->pos;
	horizontal = vmult(cam->right_normal, u);
	vertical = vmult(cam->up_normal, v);
	vp_point = vplus(cam->left_bottom, horizontal);
	vp_point = vplus(vp_point, vertical);
	ray.orivec = vunit(vminus(vp_point, ray.pos));
	return (ray);
}

void	mlx_pixel_put_img(t_mlx *mlx, int i, int j, int color)
{
	char	*tmp;

	tmp = mlx->img.addr + (j * mlx->img.line_len + (i * mlx->img.bpp / 8));
	*(int *)tmp = color;
}

double	clamp(double x)
{
	if (x < 0)
		return (0);
	else if (x > 1)
		return (1);
	else
		return (x);
}

int	get_color(t_vec3 pixel)
{
	int	x;
	int	y;
	int	z;

	x = clamp(pixel.x) * 255;
	y = clamp(pixel.y) * 255;
	z = clamp(pixel.z) * 255;
	return (x << 16 | y << 8 | z);
}

void	render(t_list *obj, t_mlx *mlx)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_ray		ray;
	t_camera	*temp_cam;
	t_vec3		color;

	temp_cam = obj_find_cam(obj);
	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			u = (double)i / (WIDTH - 1);
			v = (double)j / (HEIGHT - 1);
			ray = ray_primary(temp_cam, u, v);
			color = ray_color(); ///////////////////////////
			mlx_pixel_put_img(mlx, i, j, get_color(color));
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
}

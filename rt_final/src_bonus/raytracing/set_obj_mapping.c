/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:27:01 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 16:01:40 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"
#define RED 16
#define GREEN 8
#define BLUE 0

static int	pixel_extract_to_rgb(int mlx_color, int type)
{
	return ((mlx_color >> type) & 0xFF);
}

static t_vec3	get_pixel_to_rgb(int mlx_color)
{
	double	r;
	double	g;
	double	b;

	r = (double)pixel_extract_to_rgb(mlx_color, RED) / 256;
	g = (double)pixel_extract_to_rgb(mlx_color, GREEN) / 256;
	b = (double)pixel_extract_to_rgb(mlx_color, BLUE) / 256;
	return (vec3(r, g, b));
}

static int	get_xpm_pixel(t_xpm_img *xpm_img, int x, int y)
{
	char	*ret;

	x = ft_clamp_int(x, 0, xpm_img->width - 1);
	y = ft_clamp_int(y, 0, xpm_img->height - 1);
	ret = xpm_img->img.addr
		+ (y * xpm_img->img.line + x * (xpm_img->img.bpp / 8));
	return (*(unsigned int *)ret);
}

t_vec3	set_color_mapping(double u, double v, t_xpm_img *img)
{
	int	u_int;
	int	v_int;
	int	mlx_color;

	u_int = (int)(u * img->width);
	v_int = (int)((1.0 - v) * img->height);
	mlx_color = get_xpm_pixel(img, u_int, v_int);
	return (get_pixel_to_rgb(mlx_color));
}

t_vec3	set_normal_mapping(t_hit_record *rec, t_xpm_img *img)
{
	int		u_int;
	int		v_int;
	int		mlx_color;
	t_vec3	normal_color;

	u_int = (int)(rec->u * img->width);
	v_int = (int)((1.0 - rec->v) * img->height);
	mlx_color = get_xpm_pixel(img, u_int, v_int);
	normal_color = get_pixel_to_rgb(mlx_color);
	normal_color = vminus(vmult(normal_color, 2), vec3(1, 1, 1));
	return (vmult_matrix
		(rec->u_orivec, rec->v_orivec, rec->normal, normal_color));
}

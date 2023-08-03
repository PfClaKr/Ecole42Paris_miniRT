/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:18:06 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 04:30:24 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_bonus.h"

t_texture	*ft_find_texture(t_list *objects)
{
	if (objects->id == PL)
		return (&((t_plane *)(objects->data))->texture);
	else if (objects->id == SP)
		return (&((t_sphere *)(objects->data))->texture);
	else if (objects->id == CY)
		return (&((t_cylinder *)(objects->data))->texture);
	else if (objects->id == CO)
		return (&((t_cone *)(objects->data))->texture);
	return (NULL);
}

void	mlx_destroy_xpm_image(t_data *data)
{
	t_list		*objects;
	t_texture	*temp;

	objects = data->objects;
	while (objects)
	{
		temp = ft_find_texture(objects);
		objects = objects->next;
		if (!temp)
			continue ;
		if (temp->has_image == 1)
			mlx_destroy_image(data->mlx.mlx_ptr, temp->image.map.img_ptr);
		if (temp->has_bump == 1)
			mlx_destroy_image(data->mlx.mlx_ptr, temp->bump.map.img_ptr);
	}
}

int	mlx_close(t_data *data)
{
	mlx_destroy_xpm_image(data);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.img.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img.img_ptr);
	if (data->mlx.mlx_ptr)
		mlx_destroy_display(data->mlx.mlx_ptr);
	ft_list_destroy(&data->objects, &free);
	free(data->mlx.mlx_ptr);
	exit(0);
}

int	mlx_keyhook(int key, t_data *data)
{
	if (key == 65307)
		mlx_close(data);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		return (-1);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			WIDTH, HEIGHT, "miniRT_bonus");
	if (!data->mlx.win_ptr)
		return (-1);
	data->mlx.img.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
	if (!data->mlx.img.img_ptr)
		return (-1);
	data->mlx.img.addr = mlx_get_data_addr(data->mlx.img.img_ptr,
			&data->mlx.img.bpp, &data->mlx.img.line_len, &data->mlx.img.endian);
	if (!data->mlx.img.addr)
		return (-1);
	mlx_hook(data->mlx.win_ptr, 33, 0L, mlx_close, data);
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, mlx_keyhook, data);
	return (0);
}

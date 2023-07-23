/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:18:06 by ychun             #+#    #+#             */
/*   Updated: 2023/07/23 22:52:06 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	mlx_close(t_mlx *mlx)
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
}

void	mlx_keyhook(int key, t_mlx *mlx)
{
	if (key == 65307)
		mlx_close(mlx);
}

int	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (-1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx->win_ptr)
		return (-1);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
		return (-1);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
	if (!mlx->img.addr)
		return (-1);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, mlx_close, mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, mlx_keyhook, mlx);
	//mlx_key_hook(mlx->win_ptr, mlx_keyhook, mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:21:23 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:47:21 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	mlx_pixel_put_img(t_mlx *mlx, int i, int j, int color)
{
	char	*tmp;

	tmp = mlx->img.addr + (j * mlx->img.line_len + (i * mlx->img.bpp / 8));
	*(int *)tmp = color;
}

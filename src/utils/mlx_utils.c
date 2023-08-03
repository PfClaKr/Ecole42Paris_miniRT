/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:21:23 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:30:45 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	mlx_pixel_put_img(t_mlx *mlx, int i, int j, int color)
{
	char	*tmp;

	tmp = mlx->img.addr + (j * mlx->img.line_len + (i * mlx->img.bpp / 8));
	*(int *)tmp = color;
}

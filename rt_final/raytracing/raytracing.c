/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:53 by ychun             #+#    #+#             */
/*   Updated: 2023/07/23 21:48:09 ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

int	raytracing(t_list *obj)
{
	t_mlx	mlx;

	if (init_mlx(&mlx) == -1)
	{
		mlx_close(&mlx);
		return (-1);
	}
//	render(obj, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

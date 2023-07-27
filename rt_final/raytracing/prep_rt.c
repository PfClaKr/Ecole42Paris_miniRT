/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:45:44 by ychun             #+#    #+#             */
/*   Updated: 2023/07/25 01:20:07 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

int	prep_rt(t_data *data)
{
	t_ray	ray;

	if (init_mlx(data) == -1)
		mlx_close(data);
	raytracing(data->objects, &data->mlx, ray);
	mlx_loop(data->mlx.mlx_ptr);
	return (0);
}

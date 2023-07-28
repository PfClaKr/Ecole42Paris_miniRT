/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:10:45 by ychun             #+#    #+#             */
/*   Updated: 2023/07/28 03:01:26 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_color(t_vec3 pixel)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = pixel.x;
	g = pixel.y;
	b = pixel.z;
	if (r > 255)
		r = 255;
	else if (g > 255)
		g = 255;
	else if (b > 255)
		b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
}

// int	get_color(t_vec3 pixel)
// {
// 	int	x;
// 	int	y;
// 	int	z;

// 	x = ft_clamp(pixel.x) * 255;
// 	y = ft_clamp(pixel.y) * 255;
// 	z = ft_clamp(pixel.z) * 255;
// 	return (x << 16 | y << 8 | z);
// }

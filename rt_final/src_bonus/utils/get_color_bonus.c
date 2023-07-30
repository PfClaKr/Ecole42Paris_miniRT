/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:10:45 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:47:15 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	get_color(t_vec3 pixel)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = (int)pixel.x;
	g = (int)pixel.y;
	b = (int)pixel.z;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
}
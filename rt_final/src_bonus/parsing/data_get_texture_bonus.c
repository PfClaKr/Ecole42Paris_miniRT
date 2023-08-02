/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get_texture_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:32:53 by ychun             #+#    #+#             */
/*   Updated: 2023/08/02 01:56:30 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static t_texture	init_texture(void)
{
	t_texture	texture;

	texture.is_checker = 0;
	texture.has_image = 0;
	texture.has_bump = 0;
	return (texture);
}

static t_xpm	data_get_xpm(char *r_path, t_data *d)
{
	t_xpm	xpm;

	xpm.map.img_ptr = mlx_xpm_file_to_image(d->mlx.mlx_ptr, r_path,
			&xpm.width, &xpm.height);
	xpm.map.addr = mlx_get_data_addr(xpm.map.img_ptr, &xpm.map.bpp, &xpm.map.line_len, &xpm.map.endian);
	return (xpm);
}

t_texture	data_get_texture(char **data, t_data *d)
{
	t_texture	texture;
	int			i;

	texture = init_texture();
	if (count_double_arr(data) < 1)
		return (texture);
	i = 0;
	while (data[i])
	{
		if (ft_strcmp(data[i], "checker") == 0)
		{
			texture.is_checker = 1;
			i += 1;
		}
		else if (ft_strcmp(data[i], "image") == 0)
		{
			texture.has_image = 1;
			texture.image = data_get_xpm(data[i + 1], d);
			i += 2;
		}
		else if (ft_strcmp(data[i], "bump") == 0)
		{
			texture.has_bump = 1;
			texture.bump = data_get_xpm(data[i + 1], d);
			i += 2;
		}
	}
	return (texture);
}

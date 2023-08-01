#include "parse_bonus.h"

static t_texture	init_texture(void)
{
	t_texture texture;

	texture.is_checker = 0;
	texture.has_image = 0;
	texture.has_bump = 0;
	return (texture);
}

static t_xpm	data_get_xpm(char *r_path, t_data *d)
{
	t_xpm	xpm;

	xpm.width = 32;
	xpm.height = 32;
	xpm.map.img_ptr = mlx_xpm_file_to_image(&d->mlx, r_path,
			&xpm.width, &xpm.height);
	// xpm.map.img_ptr = NULL <------ don't know why, maybe because &d->mlx is wrong
	// Segmenation fault here! //
	xpm.map.addr = mlx_get_data_addr(xpm.map.img_ptr, &xpm.map.bpp, &xpm.map.line_len, &xpm.map.endian);
	/////////////////////////////
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

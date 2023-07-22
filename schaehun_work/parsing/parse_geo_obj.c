#include "parse.h"

t_list	*parse_object_pl(char **data)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->pos = data_get_pos(data[1]);
	pl->orivec = data_get_orivec(data[2]);
	pl->color = data_get_color(data[3]);
	return (ft_list_new(pl));
}

t_list	*parse_object_sp(char **data)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->pos = data_get_pos(data[1]);
	sp->diameter = data_get_size(data[2]);
	sp->color = data_get_color(data[3]);
	return (ft_list_new(sp));
}

t_list	*parse_object_cy(char **data)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->pos = data_get_pos(data[1]);
	cy->orivec = data_get_orivec(data[2]);
	cy->diameter = data_get_size(data[3]);
	cy->height = data_get_size(data[4]);
	cy->color = data_get_color(data[5]);
	return (ft_list_new(cy));
}


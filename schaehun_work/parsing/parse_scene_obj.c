#include "parse.h"

t_list	*parse_object_a(char **data)
{
	t_ambient_light	*a;

	a = malloc(sizeof(t_ambient_light));
	if (!a)
		return (NULL);
	a->ratio = data_get_ratio(data[1]);
	a->color = data_get_color(data[2]);
	return (ft_list_new(a));
}

t_list	*parse_object_c(char **data)
{
	t_camera	*c;

	c = malloc(sizeof(t_camera));
	if (!c)
		return (NULL);
	c->pos = data_get_pos(data[1]);
	c->orivec = data_get_orivec(data[2]);
	c->fov = data_get_fov(data[3]);
	return (ft_list_new(c));
}

t_list	*parse_object_l(char **data)
{
	t_light	*l;

	l = malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = data_get_pos(data[1]);
	l->ratio = data_get_ratio(data[2]);
	l->color = data_get_color(data[3]);
	return (ft_list_new(l));
}

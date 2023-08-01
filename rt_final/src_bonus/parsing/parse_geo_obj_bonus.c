/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_geo_obj_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:52 by ychun             #+#    #+#             */
/*   Updated: 2023/08/02 00:03:08 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

t_list	*parse_object_pl(char **data, t_data *d)
{
	t_plane	*pl;
	t_list	*obj;

	pl = malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->pos = data_get_pos(data[1]);
	pl->orivec = data_get_orivec(data[2]);
	pl->color = data_get_color(data[3]);
	pl->texture = data_get_texture(&data[4], d);
	obj = ft_list_new(pl);
	obj->id = PL;
	return (obj);
}

t_list	*parse_object_sp(char **data, t_data *d)
{
	t_sphere	*sp;
	t_list		*obj;

	sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->pos = data_get_pos(data[1]);
	sp->diameter = data_get_size(data[2]);
	sp->color = data_get_color(data[3]);
	sp->texture = data_get_texture(&data[4], d);
	obj = ft_list_new(sp);
	obj->id = SP;
	return (obj);
}

t_list	*parse_object_cy(char **data, t_data *d)
{
	t_cylinder	*cy;
	t_list		*obj;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->pos = data_get_pos(data[1]);
	cy->orivec = data_get_orivec(data[2]);
	cy->diameter = data_get_size(data[3]);
	cy->height = data_get_size(data[4]);
	cy->color = data_get_color(data[5]);
	cy->texture = data_get_texture(&data[6], d);
	obj = ft_list_new(cy);
	obj->id = CY;
	return (obj);
}

t_list	*parse_object_co(char **data, t_data *d)
{
	t_cone	*co;
	t_list	*obj;

	co = malloc(sizeof(t_cone));
	if (!co)
		return (NULL);
	co->pos = data_get_pos(data[1]);
	co->orivec = data_get_orivec(data[2]);
	co->diameter = data_get_size(data[3]);
	co->height = data_get_size(data[4]);
	co->color = data_get_color(data[5]);
	co->texture = data_get_texture(&data[6], d);
	obj = ft_list_new(co);
	obj->id = CO;
	return (obj);
}

t_list	*parse_object_cu(char **data, t_data *d)
{
	t_cube	*cu;
	t_list	*obj;

	cu = malloc(sizeof(t_cube));
	if (!cu)
		return (NULL);
	cu->pos = data_get_pos(data[1]);
	cu->orivec = data_get_orivec(data[2]);
	cu->width = data_get_size(data[3]);
	cu->color = data_get_color(data[4]);
	cu->texture = data_get_texture(&data[5], d);
	obj = ft_list_new(cu);
	obj->id = CU;
	return (obj);
}

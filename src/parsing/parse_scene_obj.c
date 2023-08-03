/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:42:57 by ychun             #+#    #+#             */
/*   Updated: 2023/07/30 21:31:51 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_list	*parse_object_a(char **data)
{
	t_ambient_light	*a;
	t_list			*obj;

	a = malloc(sizeof(t_ambient_light));
	if (!a)
		return (NULL);
	a->ratio = data_get_ratio(data[1]);
	a->color = data_get_color(data[2]);
	obj = ft_list_new(a);
	obj->id = A;
	return (obj);
}

t_list	*parse_object_c(char **data)
{
	t_camera	*c;
	t_list		*obj;

	c = malloc(sizeof(t_camera));
	if (!c)
		return (NULL);
	c->pos = data_get_pos(data[1]);
	c->orivec = data_get_orivec(data[2]);
	c->fov = data_get_fov(data[3]);
	obj = ft_list_new(c);
	obj->id = C;
	return (obj);
}

t_list	*parse_object_l(char **data)
{
	t_light	*l;
	t_list	*obj;

	l = malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = data_get_pos(data[1]);
	l->ratio = data_get_ratio(data[2]);
	l->color = vec3(255, 255, 255);
	obj = ft_list_new(l);
	obj->id = L;
	return (obj);
}

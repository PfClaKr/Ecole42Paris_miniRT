/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:47:46 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 22:42:44 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include <fcntl.h>

t_list	*parse_object_by_id(char **data, t_data *d)
{
	char	*id;

	if (!data)
		return (NULL);
	id = data[0];
	if (ft_strcmp(id, "A") == 0)
		return (parse_object_a(data));
	else if (ft_strcmp(id, "C") == 0)
		return (parse_object_c(data));
	else if (ft_strcmp(id, "L") == 0 || ft_strcmp(id, "l") == 0)
		return (parse_object_l(data));
	else if (ft_strcmp(id, "pl") == 0)
		return (parse_object_pl(data, d));
	else if (ft_strcmp(id, "sp") == 0)
		return (parse_object_sp(data, d));
	else if (ft_strcmp(id, "cy") == 0)
		return (parse_object_cy(data, d));
	else if (ft_strcmp(id, "co") == 0)
		return (parse_object_co(data, d));
	else if (ft_strcmp(id, "cu") == 0)
		return (parse_object_cu(data, d));
	return (NULL);
}

void	parse_object(t_data *d, char *filename)
{
	int		fd;
	char	**data;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		data = parse_get_data(fd);
		if (ft_list_append(&d->objects, parse_object_by_id(data, d)) == -1)
			break ;
		free_double_arr(data);
	}
	close(fd);
}

int	parse(t_data *data, char *filename)
{
	if (filename_check(filename, "rt") == -1)
		return (-1);
	if (data_integrity_check(filename) == -1)
		return (-1);
	parse_object(data, filename);
	return (0);
}

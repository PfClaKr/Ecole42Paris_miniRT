/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_integrity_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:47 by ychun             #+#    #+#             */
/*   Updated: 2023/07/30 22:07:27 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <fcntl.h>

int	data_check_by_id(char **data)
{
	char	*id;
	int		ret;

	if (!data || !data[0])
		return (-2);
	id = data[0];
	ret = -1;
	if (ft_strcmp(id, "A") == 0)
		ret = data_check_a(data);
	else if (ft_strcmp(id, "C") == 0)
		ret = data_check_c(data);
	else if (ft_strcmp(id, "L") == 0)
		ret = data_check_l(data);
	else if (ft_strcmp(id, "pl") == 0)
		ret = data_check_pl(data);
	else if (ft_strcmp(id, "sp") == 0)
		ret = data_check_sp(data);
	else if (ft_strcmp(id, "cy") == 0)
		ret = data_check_cy(data);
	return (ret);
}

int	data_integrity_check(char *filename)
{
	int		fd;
	int		ret;
	int		unique_obj;
	char	**data;

	fd = open(filename, O_RDONLY);
	unique_obj = 0;
	while (1)
	{
		data = parse_get_data(fd);
		ret = data_check_by_id(data);
		if (ret == -1)
		{
			free_double_arr(data);
			return (close(fd), -1);
		}
		else if (ret == -2)
			break ;
		unique_obj += ret;
		free_double_arr(data);
	}
	close(fd);
	if (unique_obj != 37)
		return (-1);
	return (0);
}

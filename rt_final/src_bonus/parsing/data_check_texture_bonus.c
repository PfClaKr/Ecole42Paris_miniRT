/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_texture_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:12:13 by ychun             #+#    #+#             */
/*   Updated: 2023/08/02 02:12:14 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static int	data_check_checker(char **data, int *c)
{
	if (!data[0])
		return (-1);
	if (ft_strcmp(data[0], "checker") != 0)
		return (-1);
	if (*c == 0 || *c == 11)
		*c += 14;
	else
		*c = -1;
	return (0);
}

static int	data_check_image(char **data, int *c)
{
	if (!data[0] || !data[1])
		return (-1);
	if (ft_strcmp(data[0], "image") != 0)
		return (-1);
	if (filename_check(data[1], "xpm") == -1)
		return (-1);
	if (*c == 0 || *c == 11)
		*c += 12;
	else
		*c = -1;
	return (0);
}

static int	data_check_bump(char **data, int *c)
{
	if (!data[0] || !data[1])
		return (-1);
	if (ft_strcmp(data[0], "bump") != 0)
		return (-1);
	if (filename_check(data[1], "xpm") == -1)
		return (-1);
	if (*c <= 14 && *c != -1)
		*c += 11;
	else
		*c = -1;
	return (0);
}

int	data_check_texture(char **data)
{
	int	i;
	int	c;

	if (count_double_arr(data) < 1)
		return (0);
	i = 0;
	c = 0;
	while (data[i])
	{
		if (data_check_checker(&data[i], &c) == 0)
			i += 1;
		else if (data_check_image(&data[i], &c) == 0)
			i += 2;
		else if (data_check_bump(&data[i], &c) == 0)
			i += 2;
		else
			return (-1);
		if (c == -1)
			return (-1);
	}
	return (0);
}

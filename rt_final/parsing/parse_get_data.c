/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:47:43 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:47:44 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_empty_str(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t'\
				&& str[i] != '\v' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	**parse_get_data(int fd)
{
	char	*line;
	char	**data;

	line = tab_to_space(get_line(fd));
	while (is_empty_str(line))
	{
		free(line);
		line = tab_to_space(get_line(fd));
	}
	if (!line)
		return (NULL);
	data = ft_split(line, ' ');
	free(line);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:00:17 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 17:21:27 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include <fcntl.h>

int	filename_check(char *filename, char *extension)
{
	int	fd;
	int	len;
	int	filename_len;

	if (!filename)
		return (-1);
	if (!extension)
		return (0);
	len = ft_strlen(filename);
	filename_len = ft_strlen(ft_strrchr(filename, '/'));
	if (len < 4 || filename_len < 4)
		return (-1);
	if (!ft_strcmp(ft_strrchr(filename, '.'), extension) == 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

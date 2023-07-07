/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:25:53 by ychun             #+#    #+#             */
/*   Updated: 2022/11/01 01:02:30 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_fd(int fd)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (-1);
	i = read(fd, buf, 0);
	free(buf);
	if (i >= 0)
		return (1);
	else
		return (-1);
}

static char	*ft_result_line(char *final_line)
{
	char	*result_line;
	int		len_line;
	int		i;

	len_line = 0;
	i = 0;
	if (!final_line[len_line])
		return (0);
	while (final_line[len_line] && final_line[len_line] != '\n')
		len_line++;
	result_line = (char *)malloc(sizeof(char) * (len_line + 2));
	if (!result_line)
		return (0);
	while (final_line[i] && final_line[i] != '\n')
	{
		result_line[i] = final_line[i];
		i++;
	}
	if (final_line[i] == '\n')
	{
		result_line[i] = final_line[i];
		i++;
	}
	result_line[i] = '\0';
	return (result_line);
}

static int	ft_final_line(char **final_line)
{
	char	*new_final_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*final_line)[i] && (*final_line)[i] != '\n')
		i++;
	if (!(*final_line)[i])
	{
		free(*final_line);
		*final_line = 0;
		return (1);
	}
	new_final_line = malloc(sizeof(char) * (ft_strlen2(*final_line) - i + 1));
	if (!new_final_line)
		return (0);
	while ((*final_line)[++i])
		new_final_line[j++] = (*final_line)[i];
	new_final_line[j] = '\0';
	free(*final_line);
	*final_line = new_final_line;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*final_line;
	char		*result_line;
	char		*buffer;
	int			len_read;

	len_read = ft_check_fd(fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || len_read == -1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr2(final_line, '\n') && len_read > 0)
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		buffer[len_read] = '\0';
		final_line = ft_strjoin2(final_line, buffer);
	}
	free(buffer);
	result_line = ft_result_line(final_line);
	if (!ft_final_line(&final_line))
		return (0);
	return (result_line);
}

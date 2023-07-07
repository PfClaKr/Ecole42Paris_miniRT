/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:25:55 by ychun             #+#    #+#             */
/*   Updated: 2022/11/01 01:44:33 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strcpy2(char *dest, char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[ft_strlen(s1) + j] = '\0';
	return (dest);
}

char	*ft_strchr2(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen2(s1);
	len_s2 = ft_strlen2(s2);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
	{
		free(s2);
		return (0);
	}
	new_s = (char *)malloc((sizeof(char) * (len_s1 + len_s2 + 1)));
	if (!new_s)
		return (0);
	new_s = ft_strcpy2(new_s, s1, s2);
	free (s1);
	return (new_s);
}

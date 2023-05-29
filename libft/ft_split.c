/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chun <chun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:10:23 by chun             #+#    #+#             */
/*   Updated: 2021/12/02 19:29:58 by chun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_c(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static int	ft_splitlen(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_is_c(s[i], c))
			i++;
		if (s[i] && !ft_is_c(s[i], c))
		{
			while (s[i] && !ft_is_c(s[i], c))
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static char	**ft_split_free(char **new_s)
{
	int	i;

	i = 0;
	while (!new_s[i])
		free(new_s[i++]);
	free(new_s);
	return (0);
}

static char	*ft_split_strdup(char const *s, char c)
{
	int		i;
	char	*new_s;

	i = 0;
	while (s[i] && !ft_is_c(s[i], c))
		i++;
	new_s = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_s)
		return (0);
	i = 0;
	while (s[i] && !ft_is_c(s[i], c))
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**new_s;

	i = 0;
	if (s == 0)
		return (0);
	new_s = (char **)malloc(sizeof(char *) * (ft_splitlen(s, c) + 1));
	if (!new_s)
		return (0);
	while (*s)
	{
		while (*s && ft_is_c(*s, c))
			s++;
		if (*s && !ft_is_c(*s, c))
		{
			new_s[i] = ft_split_strdup(s, c);
			if (!new_s[i])
				return (ft_split_free(new_s));
			i++;
			while (*s && !ft_is_c(*s, c))
				s++;
		}
	}
	new_s[i] = 0;
	return (new_s);
}

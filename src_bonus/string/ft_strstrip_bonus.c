/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrip_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:18:53 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:44:57 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_bonus.h"

char	*ft_strstrip(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	*strip;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	j = ft_strlen(str) - 1;
	while (str[j] && str[j] == c)
		j--;
	strip = malloc(sizeof(char) * (j - i + 1 + 1));
	if (!strip)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		strip[k] = str[i];
		i++;
		k++;
	}
	strip[k] = '\0';
	free(str);
	return (strip);
}

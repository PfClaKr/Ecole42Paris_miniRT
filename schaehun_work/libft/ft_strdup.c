/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:18:54 by ychun             #+#    #+#             */
/*   Updated: 2021/11/27 18:18:58 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len_s1;
	char	*new_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	new_s1 = malloc(sizeof(char) * (len_s1 + 1));
	if (!new_s1)
		return (0);
	while (i < len_s1)
	{
		new_s1[i] = s1[i];
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}

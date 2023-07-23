/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:22:35 by ychun             #+#    #+#             */
/*   Updated: 2021/12/02 21:17:49 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*new_s;

	if (!s)
		return (0);
	i = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (len > (len_s - start))
		new_s = (char *)malloc(sizeof(char) * (len_s - start + 1));
	else
		new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (0);
	while (i < len && start + i < len_s + 1)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

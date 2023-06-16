/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:10:22 by ychun             #+#    #+#             */
/*   Updated: 2021/12/02 22:23:29 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		back;
	char		*new_s1;

	front = 0;
	back = ft_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[back - 1] && ft_strchr(set, s1[back - 1]))
	{
		if (back - 1 < 1)
			break ;
		back--;
	}
	if (front >= back)
		return (ft_strdup(""));
	new_s1 = (char *)malloc(sizeof(char) * (back - front + 1));
	if (!new_s1)
		return (0);
	ft_strlcpy(new_s1, s1 + front, back - front + 1);
	return (new_s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:17:49 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 14:17:50 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(char *str, char c)
{
	int	i;

	if (!str || !c)
		return (str);
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i + 1]);
		i--;
	}
	return (str);
}
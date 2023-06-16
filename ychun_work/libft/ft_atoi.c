/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:07:08 by ychun             #+#    #+#             */
/*   Updated: 2021/12/02 19:55:46 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				negative;
	int				i;
	unsigned int	value;

	negative = 1;
	i = ft_isspace(str);
	value = 0;
	if (str[i] == '-')
		negative *= -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value += (str[i] - '0');
		if (value > 2147483647 && negative == 1)
			return (-1);
		if (value > 2147483648 && negative == -1)
			return (0);
		i++;
	}
	return (value * negative);
}

// #include <stdio.h>

// int	main()
// {
// 	char str[] = "1234567890";
// 	int	i = 0;

// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chun <chun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:25:47 by chun             #+#    #+#             */
/*   Updated: 2021/12/02 19:28:52 by chun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	result;

	result = 0;
	if (n <= 0)
		result = 1;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len_n;
	int			flag;
	long int	cpy_n;

	len_n = ft_intlen(n);
	flag = 1;
	cpy_n = n;
	if (n < 0)
	{
		flag *= -1;
		cpy_n *= -1;
	}
	str = (char *)malloc(sizeof(char) * len_n + 1);
	if (!str)
		return (0);
	str[len_n] = '\0';
	while (len_n-- > 0)
	{
		str[len_n] = '0' + (cpy_n % 10);
		cpy_n /= 10;
	}
	if (flag == -1)
		str[0] = '-';
	return (str);
}

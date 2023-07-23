/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:55:00 by ychun             #+#    #+#             */
/*   Updated: 2022/10/31 21:37:00 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_len(unsigned int x, int len)
{
	if (x == 0 && len == 0)
		return (1);
	while (x != 0)
	{
		len++;
		x /= 16;
	}
	return (len);
}

int	ft_puthex(unsigned int x, char format)
{
	char	*base_low;
	char	*base_up;
	int		len;

	len = 0;
	base_low = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	if (x >= 16)
	{
		ft_puthex(x / 16, format);
		ft_puthex(x % 16, format);
	}
	else if (format == 'x')
		write (1, &base_low[x], 1);
	else if (format == 'X')
		write (1, &base_up[x], 1);
	return (ft_puthex_len(x, len));
}

int	ft_putpointer_len(unsigned long p)
{
	int	len;

	len = 2;
	if (p == 0)
		return (3);
	while (p != 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

int	ft_convert_pointer(unsigned long p)
{
	char	*base;

	base = "0123456789abcdef";
	if (p >= 16)
	{
		ft_convert_pointer(p / 16);
		ft_convert_pointer(p % 16);
	}
	else
		write (1, &base[p], 1);
	return (ft_putpointer_len(p));
}

int	ft_putpointer(unsigned long p)
{
	int	len;

	if (p == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	write (1, "0x", 2);
	len = ft_convert_pointer(p);
	return (len);
}

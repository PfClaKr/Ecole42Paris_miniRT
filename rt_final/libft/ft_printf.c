/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:20:54 by ychun             #+#    #+#             */
/*   Updated: 2022/10/31 21:36:53 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putpercent(void)
{
	write (1, "%", 1);
	return (1);
}

static int	ft_type(va_list ap, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		len += ft_putpointer(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_putunsignednbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		len += ft_putpercent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_type(ap, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

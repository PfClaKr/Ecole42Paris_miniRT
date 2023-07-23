/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:21:54 by ychun             #+#    #+#             */
/*   Updated: 2022/10/29 19:39:04 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_len(long n);
int	ft_putnbr(int n);
int	ft_putunsignednbr(unsigned int n);

int	ft_puthex_len(unsigned int x, int len);
int	ft_puthex(unsigned int x, char format);
int	ft_putpointer_len(unsigned long p);
int	ft_convert_pointer(unsigned long p);
int	ft_putpointer(unsigned long p);
#endif

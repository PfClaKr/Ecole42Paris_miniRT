/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:11 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:46:12 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdouble(char *str)
{
	int	i;
	int	dec_mark;

	if (!str)
		return (0);
	dec_mark = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else if (str[i] == '.' && str[i + 1] && dec_mark == 0)
			dec_mark = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
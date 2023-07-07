/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:01:30 by ychun             #+#    #+#             */
/*   Updated: 2023/06/05 00:16:22 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *str, int status)
{
	if (!str)
		write(status, "Error\n", 6);
	else
		write(status, *str, ft_strlen(str));
	exit(status);
}
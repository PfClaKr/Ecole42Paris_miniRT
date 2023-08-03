/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:01:30 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 15:32:52 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include "../string/ft_string.h"

void	ft_error(char *str, int status)
{
	if (!str)
		write(2, "Error\n", 6);
	else
		write(2, str, ft_strlen(str));
	if (status)
		exit(-1);
}

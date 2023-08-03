/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rand_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:55:30 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 02:33:26 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	get_rand_num(int anti)
{
	int	ret;

	if (anti == 0)
		return (0);
	ret = rand();
	return (ret);
}

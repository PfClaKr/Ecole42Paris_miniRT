/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tan_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:31 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:47:18 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include <math.h>

float	get_tan(float degree)
{
	static float	radian;

	radian = M_PI / 180;
	return (tan(degree * radian));
}

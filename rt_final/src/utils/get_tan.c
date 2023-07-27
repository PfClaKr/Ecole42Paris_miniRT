/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:31 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:46:32 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

float	get_tan(float degree)
{
	static float	radian;

	radian = M_PI / 180;
	return (tan(degree * radian));
}

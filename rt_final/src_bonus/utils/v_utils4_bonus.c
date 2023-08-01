/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:52:36 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 15:59:01 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_vec3	vmult_matrix(t_vec3 v1, t_vec3 v2, t_vec3 v3, t_vec3 normal)
{
	double	matrix[3][3];
	t_vec3	ret;

	matrix[0][0] = v1.x;
	matrix[1][0] = v1.y;
	matrix[2][0] = v1.z;
	matrix[0][1] = v2.x;
	matrix[1][1] = v2.y;
	matrix[2][1] = v2.z;
	matrix[0][2] = v3.x;
	matrix[1][2] = v3.y;
	matrix[2][2] = v3.z;
	ret.x = matrix[0][0]
		* normal.x + matrix[0][1] * normal.y + matrix[0][2] * normal.z;
	ret.y = matrix[1][0]
		* normal.x + matrix[1][1] * normal.y + matrix[1][2] * normal.z;
	ret.x = matrix[2][0]
		* normal.x + matrix[2][1] * normal.y + matrix[2][2] * normal.z;
	return (ret);
}

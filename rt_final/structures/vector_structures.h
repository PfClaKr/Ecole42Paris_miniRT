/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_structures.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:13:28 by ychun             #+#    #+#             */
/*   Updated: 2023/07/23 23:14:09 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_STRUCTURES_H
# define VECTOR_STRUCTURES_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	pos;
	t_vec3	orivec;
}	t_ray;

#endif
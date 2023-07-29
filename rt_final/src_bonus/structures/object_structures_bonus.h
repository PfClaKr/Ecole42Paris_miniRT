/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_structures_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:13:24 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:46:25 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_STRUCTURES_BONUS_H
# define OBJECT_STRUCTURES_BONUS_H

# include "data_structures_bonus.h"

typedef struct s_ambient_light
{
	double	ratio;
	t_vec3	color;
}	t_ambient_light;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orivec;
	double	fov;
	t_vec3	right_normal;
	t_vec3	up_normal;
	t_vec3	left_bottom;
	double	focal_len;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef struct s_sphere
{
	t_vec3	pos;
	double	diameter;
	double	radius;
	double	radius2;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	orivec;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	orivec;
	double	diameter;
	double	height;
	t_vec3	color;
}	t_cylinder;

#endif

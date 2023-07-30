/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:50 by ychun             #+#    #+#             */
/*   Updated: 2023/07/30 23:09:01 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_BONUS_H
# define RAYTRACING_BONUS_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include "../init/init_bonus.h"
# include "../structures/data_structures_bonus.h"

# define EPSILON 1e-6

typedef struct s_hit_record
{
	t_vec3	p;
	t_vec3	normal;
	double	tmin;
	double	tmax;
	double	t;
	int		front_face;
	t_vec3	color;
}	t_hit_record;

typedef struct s_hit_num
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	root;
	t_vec3	oc;
	t_vec3	p;
}	t_hit_num;

void	raytracing(t_list *objects, t_mlx *mlx);
int		hit_object(t_list *objects, t_ray ray, t_hit_record *rec);
int		hit_sphere(t_sphere *obj, t_ray ray, t_hit_record *rec);
int		hit_plane(t_plane *obj, t_ray ray, t_hit_record *rec);
int		hit_cylinder(t_cylinder *obj, t_ray ray, t_hit_record *rec);
t_vec3	light_model(t_list *objects, t_ray camera_ray, t_hit_record *rec);
t_vec3	phong_model(t_list *objects, t_light *obj,
			t_ray camera_ray, t_hit_record *rec);

#endif
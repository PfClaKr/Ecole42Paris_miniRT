/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:50 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:51:30 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include "../init/init.h"
# include "../structures/data_structures.h"

# define EPSILON 1e-6

typedef struct s_hit_record
{
	t_vec3	p;
	t_vec3	normal;
	double	tmin;
	double	tmax;
	double	t;
	int		front_face;
	t_vec3	albedo;
}	t_hit_record;

int		prep_rt(t_data *data);
void	raytracing(t_list *obj, t_mlx *mlx);
int		hit_sphere(t_sphere *data, t_ray ray, t_hit_record *rec);

#endif
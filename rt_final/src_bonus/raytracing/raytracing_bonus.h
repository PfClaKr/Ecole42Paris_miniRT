/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:50 by ychun             #+#    #+#             */
/*   Updated: 2023/08/02 00:29:35 by schaehun         ###   ########.fr       */
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
	t_vec3	u_orivec;
	t_vec3	v_orivec;
	double	u;
	double	v;
}	t_hit_record;

typedef struct s_hit_num
{
	double	a;
	double	half_b;
	double	c;
	double	h_ratio;
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
int		hit_corn(t_cylinder *obj, t_ray ray, t_hit_record *rec);

t_vec3	light_model(t_list *objects, t_ray camera_ray, t_hit_record *rec);
t_vec3	phong_model(t_list *objects, t_light *obj,
			t_ray camera_ray, t_hit_record *rec);

void	get_sphere_uv_value(t_hit_record *rec);
void	get_plane_uv_value(t_hit_record *rec);
void	get_cylinder_uv_value(t_cylinder *obj, t_hit_record *rec);
void	get_cone_uv_value(t_cone *obj, t_hit_record *rec);

t_vec3	set_color_checker(double u, double v);
void	set_obj_color(t_texture texture, t_hit_record *rec, t_vec3 obj_color);

t_vec3	set_color_mapping(double u, double v, t_xpm *img);
t_vec3	set_normal_mapping(t_hit_record *rec, t_xpm *img);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_value_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 05:10:47 by ychun             #+#    #+#             */
/*   Updated: 2023/08/02 23:13:45 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_bonus.h"

static void	get_uv_orivec(t_vec3 *u_orivec, t_vec3 *v_orivec, t_vec3 obj_orivec)
{
	*u_orivec = vunit(vcross(vup(obj_orivec), obj_orivec));
	*v_orivec = vunit(vcross(obj_orivec, *u_orivec));
}

void	get_sphere_uv_value(t_sphere *obj, t_hit_record *rec)
{
	double	theta;
	double	phi;

	get_uv_orivec(&rec->u_orivec, &rec->v_orivec, rec->normal);
	theta = acos(-1 * rec->normal.y);
	phi = atan2(-1 * rec->normal.z, rec->normal.x) + M_PI;
	rec->u = phi * M_1_PI * 0.5; // * obj->diameter * 1.5
	rec->v = theta * M_1_PI;
	(void) obj;
}

void	get_plane_uv_value(t_hit_record *rec)
{
	get_uv_orivec(&rec->u_orivec, &rec->v_orivec, rec->normal);
	rec->u = fmod(vdot(rec->p, rec->u_orivec), 1);
	rec->v = fmod(vdot(rec->p, rec->v_orivec), 1);
	if (rec->u < 0)
		rec->u += 1;
	if (rec->v < 0)
		rec->v += 1;
}

void	get_cylinder_uv_value(t_cylinder *obj, t_hit_record *rec)
{
	double	theta;
	double	height;
	t_vec3	pc;

	get_uv_orivec(&rec->u_orivec, &rec->v_orivec, obj->orivec);
	pc = vminus(rec->p, obj->pos);
	theta = atan2(-1 * vdot(pc, rec->v_orivec), vdot(pc, rec->u_orivec)) + M_PI;
	height = vdot(pc, obj->orivec);
	rec->u = theta * M_1_PI * 0.5; //obj->diameter * 1.5
	rec->v = fmod(height, 1);
	if (rec->v < 0)
		rec->v += 1;
}

void	get_cone_uv_value(t_cone *obj, t_hit_record *rec)
{
	double	theta;
	double	height;
	t_vec3	pc;

	get_uv_orivec(&rec->u_orivec, &rec->v_orivec, obj->orivec);
	pc = vminus(rec->p, obj->pos);
	theta = atan2(-1 * vdot(pc, rec->v_orivec), vdot(pc, rec->u_orivec)) + M_PI;
	height = vdot(pc, obj->orivec);
	rec->u = theta * M_1_PI * 0.5; //obj->diameter * 1.5
	rec->v = fmod(height, 1);
	if (rec->v < 0)
		rec->v += 1;
}

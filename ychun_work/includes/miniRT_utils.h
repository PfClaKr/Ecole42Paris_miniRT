/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:28:53 by ychun             #+#    #+#             */
/*   Updated: 2023/06/05 00:53:14 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_UTILS_H
# define MINIRT_UTILS_H

# include "miniRT.h"

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
void		vset(t_vec3 *v, double x, double y, double z);
double		vlength2(t_vec3 v);
double		vlength(t_vec3 v);
t_vec3		vplus(t_vec3 v, t_vec3 v2);
t_vec3		vplus_(t_vec3 v, double x, double y, double z);
t_vec3		vminus(t_vec3 v1, t_vec3 v2);
t_vec3		vminus_(t_vec3 v, double x, double y, double z);
t_vec3		vmult(t_vec3 v, double t);
t_vec3		vmult_(t_vec3 v1, t_vec3 v2);
t_vec3		vdivide(t_vec3 v, double t);
double		vdot(t_vec3 v1, t_vec3 v2);
t_vec3		vcross(t_vec3 v1, t_vec3 v2);
t_vec3		vunit(t_vec3 v);
t_vec3		vmin(t_vec3 v1, t_vec3 v2);

#endif
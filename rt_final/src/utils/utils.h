/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:37 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:46:38 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "../structures/vector_structures.h"
# include "../structures/data_structures.h"

int		count_double_arr(char **arr);
void	free_double_arr(char **arr);

int		ft_atoi(const char *str);
double	ft_atof(const char *str);

int		ft_isint(char *str);
int		ft_isdouble(char *str);
void	ft_error(char *str, int status);

t_vec3	vec3(double x, double y, double z);
double	vdot(t_vec3 v1, t_vec3 v2);
t_vec3	vcross(t_vec3 v1, t_vec3 v2);
t_vec3	vmin(t_vec3 v1, t_vec3 v2);
t_vec3	vunit(t_vec3 v);
void	vset(t_vec3 *v, double x, double y, double z);
double	vlength2(t_vec3 v);
double	vlength(t_vec3 v);
t_vec3	vplus(t_vec3 v, t_vec3 v2);
t_vec3	vplus_(t_vec3 v, double x, double y, double z);
t_vec3	vminus(t_vec3 v1, t_vec3 v2);
t_vec3	vminus_(t_vec3 v, double x, double y, double z);
t_vec3	vmult(t_vec3 v, double t);
t_vec3	vmult_(t_vec3 v1, t_vec3 v2);
t_vec3	vdivide(t_vec3 v, double t);
float	get_tan(float degree);
double	ft_clamp(double x);
int		get_color(t_vec3 pixel);
void	mlx_pixel_put_img(t_mlx *mlx, int i, int j, int color);

#endif
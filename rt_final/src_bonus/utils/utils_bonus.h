/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:46:37 by ychun             #+#    #+#             */
/*   Updated: 2023/08/01 15:59:25 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <stdlib.h>
# include "../structures/vector_structures_bonus.h"
# include "../structures/data_structures_bonus.h"

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
t_vec3	vminus(t_vec3 v1, t_vec3 v2);
t_vec3	vmult(t_vec3 v, double t);
t_vec3	vmult_(t_vec3 v1, t_vec3 v2);
t_vec3	vdivide(t_vec3 v, double t);
t_vec3	vup(t_vec3 v);
t_vec3	vmult_matrix(t_vec3 v1, t_vec3 v2,
			t_vec3 v3, t_vec3 normal);
float	get_tan(float degree);
double	ft_clamp_double(double x);
int		ft_clamp_int(int x, int min, int max);
int		get_color(t_vec3 pixel);
void	mlx_pixel_put_img(t_mlx *mlx, int i, int j, int color);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:38:36 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 03:36:46 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "../string/ft_string_bonus.h"
# include "../utils/utils_bonus.h"
# include "../list/ft_list_bonus.h"
# include "../structures/object_structures_bonus.h"

char		**parse_get_data(int fd);

int			data_get_count(char **data);

int			data_check_ratio(char *data);
int			data_check_color(char *data);
int			data_check_pos(char *data);

int			data_check_orivec(char *data);
int			data_check_fov(char *data);
int			data_check_size(char *data);

int			data_check_texture(char **data);

int			data_check_a(char **data);
int			data_check_c(char **data);
int			data_check_l(char **data);
int			data_check_pl(char **data);
int			data_check_sp(char **data);
int			data_check_cy(char **data);
int			data_check_co(char **data);

int			filename_check(char *filename, char *extension);

int			data_check_by_id(char **data);
int			data_integrity_check(char *filename);

double		data_get_ratio(char *data);
t_vec3		data_get_color(char *data);
t_vec3		data_get_pos(char *data);
double		data_get_fov(char *data);
t_vec3		data_get_orivec(char *data);
double		data_get_size(char *data);

t_texture	data_get_texture(char **data, t_data *d);

t_list		*parse_object_a(char **data);
t_list		*parse_object_c(char **data);
t_list		*parse_object_l(char **data);
t_list		*parse_object_pl(char **data, t_data *d);
t_list		*parse_object_sp(char **data, t_data *d);
t_list		*parse_object_cy(char **data, t_data *d);
t_list		*parse_object_co(char **data, t_data *d);

t_list		*parse_object_by_id(char **data, t_data *d);
void		parse_object(t_data *d, char *filename);
int			parse(t_data *data, char *filename);

#endif
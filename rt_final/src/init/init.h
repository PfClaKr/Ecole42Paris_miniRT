/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:59 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 23:12:51 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../utils/utils.h"
# include "../structures/data_structures.h"
# include "../../settings.h"
# include "../raytracing/raytracing.h"

typedef struct s_hit_record t_hit_record;

int		init_camera(t_camera *obj);
int		init_sphere(t_sphere *obj);
int		init_objects(t_list **obj);
int		init_mlx(t_data *data);
t_ray	init_camera_ray(t_camera *cam, int u, int v);
t_ray	init_light_ray(t_light *obj, t_hit_record *rec);
int		mlx_keyhook(int key, t_data *data);
int		mlx_close(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:59 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:53:08 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../utils/utils.h"
# include "../structures/data_structures.h"
# include "../settings.h"

int		init_camera(t_camera *obj);
int		init_sphere(t_sphere *obj);
int		init_objects(t_list **obj);
int		init_mlx(t_data *data);
t_ray	init_ray(t_camera *cam, int u, int v);
int		mlx_keyhook(int key, t_data *data);
int		mlx_close(t_data *data);

#endif
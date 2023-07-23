/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:59 by ychun             #+#    #+#             */
/*   Updated: 2023/07/23 22:43:45 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../utils/utils.h"
# include "../structures/object_structures.h"
# include "../structures/mlx_structures.h"
# include "../mlx/mlx.h"
# include "../list/ft_list.h"
# include "../settings.h"

int		init_camera(t_camera *obj);
int		init_sphere(t_sphere *obj);
int		init_objects(t_list **obj);
int		init_mlx(t_mlx *mlx);
void	mlx_keyhook(int key, t_mlx *mlx);
void	mlx_close(t_mlx *mlx);

#endif
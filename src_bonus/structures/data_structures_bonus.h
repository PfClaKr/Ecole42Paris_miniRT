/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:33:24 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:45:21 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_BONUS_H
# define DATA_STRUCTURES_BONUS_H

# include "mlx_structures_bonus.h"
# include "object_structures_bonus.h"
# include "vector_structures_bonus.h"
# include "../list/ft_list_bonus.h"

typedef struct s_data
{
	t_mlx	mlx;
	t_list	*objects;
}	t_data;

#endif
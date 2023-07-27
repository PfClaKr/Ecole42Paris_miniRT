/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:33:24 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 18:53:53 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

# include "mlx_structures.h"
# include "object_structures.h"
# include "vector_structures.h"
# include "../list/ft_list.h"

typedef struct s_data
{
	t_mlx	mlx;
	t_list	*objects;
}	t_data;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:02:16 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 04:36:12 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "parsing/parse_bonus.h"
#include "raytracing/raytracing_bonus.h"
#include "init/init_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.objects = NULL;
	if (ac != 2)
		ft_error("Error\n./miniRT: bad arguments\n", 1);
	if (init_mlx(&data) == -1)
	{
		ft_error("Error\nmlx initialization error\n", 0);
		mlx_close(&data);
	}
	if (parse(&data, av[1]) == -1)
	{
		ft_error("Error\nparsing error\n", 0);
		mlx_close(&data);
	}
	if (init_objects(&data.objects) == -1)
	{
		ft_error("Error\nobject initialization error\n", 0);
		mlx_close(&data);
	}
	raytracing(data.objects, &data.mlx);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}

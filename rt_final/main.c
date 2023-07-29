/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:02:16 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 15:33:04 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "src/parsing/parse.h"
#include "src/raytracing/raytracing.h"
#include "src/init/init.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.objects = NULL;
	if (ac != 2)
		ft_error("Error\n./miniRT: bad arguments\n", 1);
	if (parse(&data.objects, av[1]) == -1)
		ft_error("Error\nparsing error\n", 1);
	if (init_objects(&data.objects) == -1)
	{
		ft_list_destroy(&data.objects, &free);
		ft_error("Error\nobject initialization error\n", 1);
	}
	if (init_mlx(&data) == -1)
	{
		ft_error("Error\nmlx initialization error\n", 0);
		mlx_close(&data);
	}
	raytracing(data.objects, &data.mlx);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}

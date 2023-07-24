/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:02:16 by ychun             #+#    #+#             */
/*   Updated: 2023/07/24 23:48:10 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "parsing/parse.h"
#include "raytracing/raytracing.h"
#include "init/init.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.objects = NULL;
	if (ac != 2)
		ft_error("Not good Input.\n", 2);
	if (parse(&data.objects, av[1]) == -1)
		ft_error("Not good Input.\n", 2);
	if (init_objects(&data.objects) == -1)
	{
		ft_list_destroy(&data.objects, &free);
		ft_error("Something Error. \n", 2);
	}
	prep_rt(&data);
	return (0);
}

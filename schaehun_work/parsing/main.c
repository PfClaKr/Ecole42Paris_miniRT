#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// #include "object_structures.h"
// #include "ft_list.h"
// #include "ft_string.h"
// #include "utils.h"
#include "parse.h"

int	main(void)
{
	t_list	*objects;
	t_list	*node;

	if (parse(&objects, "scene.rt") == -1)
	{
		printf("parse error\n");
		return (1);
	}
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->ratio);
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->color.x);
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->color.y);
	printf("a : %f\n", ((t_ambient_light *)(objects->data))->color.z);
	printf("\n");
	node = objects;
	while (node->next)
		node = node->next;
	printf("cy : %f\n", ((t_cylinder *)(node->data))->pos.x);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->orivec.x);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->diameter);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->height);
	printf("cy : %f\n", ((t_cylinder *)(node->data))->color.x);
	ft_list_destroy(&objects, &free);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:58:57 by ychun             #+#    #+#             */
/*   Updated: 2023/07/23 22:15:22 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_camera(t_camera *obj)
{
	t_vec3	vec_y;
	t_vec3	vec_z;
	t_vec3	temp;

	vec_y = vec3(0.0, 1.0, 0.0);
	vec_z = vec3(0.0, 0.0, -1.0);
	if (vlength(vcross(vec_y, obj->orivec)))
		obj->right_normal = vunit(vcross(obj->orivec, vec_y));
	else
		obj->right_normal = vunit(vcross(obj->orivec, vec_z));
	obj->up_normal = vunit(vcross(obj->right_normal, obj->orivec));
	obj->focal_len = (float)WIDTH / 2 / get_tan(obj->fov / 2);
	temp = vplus(obj->pos, vmult(obj->orivec, obj->focal_len));
	temp = vminus(temp, vmult(obj->right_normal, -(float)(WIDTH - 1) / 2));
	temp = vminus(temp, vmult(obj->up_normal, -(float)(HEIGHT - 1) / 2));
	obj->left_bottom = temp;
	return (0);
}

int	init_sphere(t_sphere *obj)
{
	obj->radius = obj->diameter / 2;
	obj->radius2 = obj->radius * obj->radius;
	return (0);
}

int	init_objects(t_list **obj)
{
	t_list	*tmp;
	int		ret;

	tmp = *obj;
	ret = 0;
	while (tmp)
	{
		if (tmp->id == C)
			ret = init_camera((t_camera *)(tmp->data));
		else if (tmp->id == SP)
			ret = init_sphere((t_sphere *)(tmp->data));
		tmp = tmp->next;
	}
	return (ret);
}

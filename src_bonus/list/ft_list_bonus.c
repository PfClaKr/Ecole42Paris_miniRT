/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:19:20 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:41:51 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"

void	*ft_list_find(t_list *list, enum e_types type)
{
	if (type >= 0 && type <= 6)
	{
		while (list)
		{
			if (list->id == type)
				return (list->data);
			list = list->next;
		}
	}
	return (NULL);
}

t_list	*ft_list_new(void *data)
{
	t_list	*list;

	if (!data)
		return (NULL);
	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

int	ft_list_append(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return (-1);
	if (!list || !(*list))
	{
		*list = new;
		return (0);
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

void	ft_list_destroy(t_list **list, void (*destroy)(void *))
{
	t_list	*tmp;

	if (!*list || !list)
		return ;
	tmp = *list;
	while (tmp)
	{
		*list = tmp->next;
		destroy(tmp->data);
		free(tmp);
		tmp = *list;
	}
}

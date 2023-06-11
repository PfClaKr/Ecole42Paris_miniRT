/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:55:35 by ychun             #+#    #+#             */
/*   Updated: 2021/11/29 18:42:51 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = *lst;
	if (*lst || lst)
	{
		while (new_lst)
		{
			*lst = new_lst->next;
			del(new_lst->content);
			free(new_lst);
			new_lst = *lst;
		}
	}
}

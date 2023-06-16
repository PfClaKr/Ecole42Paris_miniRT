/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:07:32 by ychun             #+#    #+#             */
/*   Updated: 2021/11/29 19:10:50 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	while (lst)
	{
		temp = ft_lstnew((f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	temp = NULL;
	return (result);
}

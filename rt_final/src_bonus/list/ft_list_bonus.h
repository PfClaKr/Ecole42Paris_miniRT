/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:19:21 by ychun             #+#    #+#             */
/*   Updated: 2023/07/31 21:30:42 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_BONUS_H
# define FT_LIST_BONUS_H

# include <stdlib.h>

enum	e_types
{
	A,
	C,
	L,
	SP,
	PL,
	CY,
};

typedef struct s_list
{
	enum e_types	id;
	void			*data;
	struct s_list	*next;
}	t_list;

t_list	*ft_list_new(void *data);
int		ft_list_append(t_list **list, t_list *new);
void	ft_list_destroy(t_list **list, void (*destroy)(void *));
void	*ft_list_find(t_list *list, enum e_types type);

#endif

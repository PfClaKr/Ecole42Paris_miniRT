#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

enum	types
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
	enum types	id;
	void		*data;
	struct s_list	*next;
}	t_list;

t_list	*ft_list_new(void *data);
int	ft_list_append(t_list **list, t_list *new);
void	ft_list_destroy(t_list **list, void (*destroy)(void *));

#endif

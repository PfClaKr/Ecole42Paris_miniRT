#include "ft_string.h"

char	*tab_to_space(char *str)
{
	int	i;
	
	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\n')
			str[i] = ' ';
	return (str);
}

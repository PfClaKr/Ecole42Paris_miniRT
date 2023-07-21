#include "utils.h"

int	ft_isint(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

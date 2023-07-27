#include "ft_string.h"

char	*ft_strrchr(char *str, char c)
{
	int	i;

	if (!str || !c)
		return (str);
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i + 1]);
		i--;
	}
	return (str);
}

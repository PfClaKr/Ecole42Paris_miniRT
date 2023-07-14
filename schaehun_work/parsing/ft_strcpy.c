#include "ft_string.h"

int	ft_strcpy(char *dst, char *src)
{
	int	i;

	if (!dst || !src)
		return (1);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (0);
}

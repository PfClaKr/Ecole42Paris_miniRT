#include "utils.h"
#include "../string/ft_string.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		sign;

	sign = 1;
	c = (char *)str;
	res = (double)ft_atoi(c);
	if (c[0] == '-' && res == 0)
		sign = -1;
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return ((res + res2) * sign);
	else
		return ((res + -res2) * sign);
}

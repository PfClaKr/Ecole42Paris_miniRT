#include "utils.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		str++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		str++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}

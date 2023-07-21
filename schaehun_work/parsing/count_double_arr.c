#include "utils.h"

int	count_double_arr(char **arr)
{
	int	i;
	
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

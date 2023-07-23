#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		count_double_arr(char **arr);
void	free_double_arr(char **arr);

int		ft_atoi(const char *str);
double	ft_atof(const char *str);

int		ft_isint(char *str);
int		ft_isdouble(char *str);

#endif

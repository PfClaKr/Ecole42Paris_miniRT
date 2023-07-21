#ifndef PARSE_H
# define PARSE_H

# include "ft_string.h"
# include "utils.h"

char	**parse_get_data(int fd);

int	data_get_count(char **data);

int	data_check_ratio(char *data);
int	data_check_color(char *data);
int	data_check_pos(char *data);

int	data_check_orivec(char *data);
int	data_check_fov(char *data);
int	data_check_size(char *data);

int	data_check_a(char **data);
int	data_check_c(char **data);
int	data_check_l(char **data);
int	data_check_pl(char **data);
int	data_check_sp(char **data);
int	data_check_cy(char **data);

int	data_check_by_id(char **data);
int	data_integrity_check(char *filename);

#endif

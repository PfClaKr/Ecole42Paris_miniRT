#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	ft_strcpy(char *dst, char *src);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strstrip(char *str, char c);
char	**ft_split(char *str, char sep);

char	*tab_to_space(char *str);

char	*get_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:18:49 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:44:45 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_BONUS_H
# define FT_STRING_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(char *str, char c);
char	*ft_strstrip(char *str, char c);
char	**ft_split(char *str, char sep);
int		ft_cntchar(char *str, char c);

char	*tab_to_space(char *str);

char	*get_line(int fd);

#endif

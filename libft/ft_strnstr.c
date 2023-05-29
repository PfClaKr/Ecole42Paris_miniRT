/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chun <chun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:20:20 by chun             #+#    #+#             */
/*   Updated: 2021/11/27 18:19:21 by chun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_hay;
	size_t	len_nee;

	len_hay = ft_strlen(haystack);
	len_nee = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (len_hay < len_nee || len < len_nee)
		return (0);
	while (haystack && len_hay >= len_nee && len >= len_nee)
	{
		if (!(ft_memcmp(haystack, needle, len_nee)))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

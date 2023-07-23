#include "ft_string.h"
#include "utils.h"

static int	jump_sep(char *str, char sep)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] == sep)
		i++;
	return (i);
}

static int	count_words(char *str, char sep)
{
	int	i;
	int	count;

	i = jump_sep(str, sep);
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == sep)
		{
			i++;
			continue ;
		}
		while (str[i] && str[i] != sep)
			i++;
		count++;
	}
	return (count);
}

static int	count_letter(char *str, char sep)
{
	int	i;

	i = jump_sep(str, sep);
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static char	**split_init(char *str, char sep, int count)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = -1;
	j = 0;
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	while (++i < count)
	{
		j += jump_sep(&str[j], sep);
		split[i] = malloc(sizeof(char) * (count_letter(&str[j], sep) + 1));
		if (!split[i])
			return (free_double_arr(split), NULL);
		k = 0;
		while (str[j] && str[j] != sep)
			split[i][k++] = str[j++];
		split[i][k] = '\0';
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split(char *str, char sep)
{
	int		count;
	char	**split;

	if (!str || !sep)
		return (NULL);
	count = count_words(str, sep);
	split = split_init(str, sep, count);
	if (!split)
		return (NULL);
	return (split);
}

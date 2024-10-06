/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:28:41 by oromashk          #+#    #+#             */
/*   Updated: 2024/09/23 12:19:07 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i++]);
	}
	free(arr);
	return (NULL);
}

static char	*fill_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	word_count(const char *s, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*s)
	{
		if (*s != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*s == c)
			x = 0;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	i;
	int		j;
	int		s_word;

	i = 0;
	j = 0;
	s_word = -1;
	arr = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			arr[j] = fill_word(s, s_word, i);
			if (!(arr[j++]))
				return (ft_free(arr, j - 1));
			s_word = -1;
		}
		i++;
	}
	return (arr);
}

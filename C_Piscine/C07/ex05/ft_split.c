/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:56:46 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/26 20:24:59 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <stdlib.h>

int	sep_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && sep_check(str[i], charset))
			i++;
		if (str[i] && !sep_check(str[i], charset))
		{
			words++;
			while (str[i] && !sep_check(str[i], charset))
				i++;
		}
	}
	return (words);
}

char	*word_dup(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !sep_check(str[i], charset))
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !sep_check(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		words;

	words = word_count(str, charset);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && sep_check(*str, charset))
			str++;
		if (*str && !sep_check(*str, charset))
		{
			arr[i] = word_dup(str, charset);
			i++;
			while (*str && !sep_check(*str, charset))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

int	main(void)
{
	char	*str;
	char	*charset;

	str = "cbebdda";
	charset = "b";
}

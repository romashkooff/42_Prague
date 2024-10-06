/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:56:39 by oromashk          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:11 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = NULL;
	if (s1 != NULL && set != NULL)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
			i++;
		while (s1[j - 1] != '\0' && ft_strchr(set, s1[j - 1]) != NULL && j > i)
			j--;
		str = (char *)malloc(j - i + 1);
		if (!str)
			return (NULL);
		else
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}

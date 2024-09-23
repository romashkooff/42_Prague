/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:41:24 by oromashk          #+#    #+#             */
/*   Updated: 2024/09/20 20:51:59 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				diff;
	size_t			size;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n < 1)
	{
		return (0);
	}
	size = n - 1;
	while (i <= size)
	{
		if (str1[i] != str2[i])
		{
			diff = (unsigned char)str1[i] - (unsigned char)str2[i];
			return (diff);
		}
		i++;
	}
	return (0);
}

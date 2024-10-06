/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:03:50 by oromashk          #+#    #+#             */
/*   Updated: 2024/09/20 20:19:21 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;
	size_t	size;

	i = 0;
	if (n < 1)
	{
		return (0);
	}
	size = n - 1;
	while ((s1[i] != '\0' || s2[i] != '\0') && i <= size)
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (diff);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	ft_strncmp("abcdef", "abc\375xx", 5);
// }

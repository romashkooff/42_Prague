/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:25:43 by oromashk          #+#    #+#             */
/*   Updated: 2024/09/20 20:02:30 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if ((char)c == '\0' && s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s;
// 	int			c;

// 	s = "teste";
// 	c = 'e';
// 	ft_strrchr(s, c);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:01:27 by romashko          #+#    #+#             */
/*   Updated: 2024/09/22 21:31:59 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < len)
			{
				if (little[++j] == '\0')
					return ((char *)big + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "lorem ipsum dolor sit amet";
// 	s2 = "ipsumm";
// 	ft_strnstr(s1, s2, 30);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:51:34 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/11 17:51:48 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	char			diff;
	unsigned int	size;

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
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char			*s1;
// 	char			*s2;
// 	unsigned int	n;

// 	s1 = "Hello";
// 	s2 = "Hellz";
// 	n = 4;
// 	ft_strncmp(s1, s2, n);
// }
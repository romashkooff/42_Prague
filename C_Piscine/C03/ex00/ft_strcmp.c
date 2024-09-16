/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:06:27 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/11 17:35:02 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	char			diff;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	diff = s1[i] - s2[i];
	return (diff);
}

// int main()
// {
// 	char *s1;
// 	char *s2;
// 	s1 = "";
// 	s2 = "A";
// 	ft_strcmp(s1, s2);
// }
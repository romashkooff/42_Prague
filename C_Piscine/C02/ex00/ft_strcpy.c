/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:02:40 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/11 17:17:14 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
	// char dest[50];

	// char * dest1;
	// char dest2[]= "abcd";

	// dest1 = dest2;

	// printf("%c",*dest1);
// 	char *src;

// 	src = "Hello world";
// 	ft_strcpy(dest, src);
// 	printf("%s", dest);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:33:27 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/14 16:21:29 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_l;
	unsigned int	src_l;

	dest_l = len(dest);
	src_l = len(src);
	if (size <= dest_l)
		return (size + src_l);
	i = dest_l;
	j = 0;
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_l + dest_l);
}

// int	main(void)
// {
// 	unsigned int n;

// 	char s1[20] = "Born to code";
// 	char *s2 = "1337 42";
// 	n = 20;
// 	ft_strlcat(s1, s2, n);
// }
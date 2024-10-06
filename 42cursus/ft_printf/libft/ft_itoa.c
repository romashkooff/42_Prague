/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:19:31 by oromashk          #+#    #+#             */
/*   Updated: 2024/09/24 12:40:14 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longlen(long nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*ft_convertion(long nbr, size_t len, char *res)
{
	int	sign;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	sign = 0;
	if (nbr < 0)
	{
		res[0] = '-';
		sign++;
		nbr = -nbr;
	}
	res[len] = '\0';
	while (--len != 0)
	{
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == 0)
		res[0] = (nbr % 10) + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	len;
	char	*res;

	nbr = n;
	res = NULL;
	if (nbr == 0)
		return (res = ft_strdup("0"));
	len = ft_longlen(nbr);
	res = ft_convertion(nbr, len, res);
	return (res);
}

// int	main(void)
// {
// 	ft_itoa(231);
// }

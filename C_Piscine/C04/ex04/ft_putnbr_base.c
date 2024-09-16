/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:13:38 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/26 20:52:13 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	str_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	base_check(char *base)
{
	int		i;
	int		j;

	if (str_len(base) <= 1)
	{
		return (0);
	}
	i = 0;
	while (i <= str_len(base))
	{
		j = i;
		while (j <= str_len(base) && base[j] != '\0')
		{
			if (base[i] == base[j + 1] || base[i] == '-' || base[i] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nmbr;

	nmbr = nbr;
	if (base_check(base) != 0)
	{
		if (nmbr < 0)
		{
			write(1, "-", 1);
			nmbr = -nmbr;
		}
		if (nmbr >= str_len(base))
			ft_putnbr_base(nmbr / str_len(base), base);
		write(1, &base[nmbr % str_len(base)], 1);
	}
}

// int	main(void)
// {
// 	int		nbr;
// 	char	*base;

// 	nbr = -2147483648;
// 	base = "01";
// 	ft_putnbr_base(nbr, base);
// }

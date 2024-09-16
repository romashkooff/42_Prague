/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:40:32 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/15 09:33:46 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putnbr(int nb)
{
	int		div;
	char	mod;

	div = 1000000000;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb < div && nb != 0 && nb != -2147483648)
		div = div / 10;
	while (div > 0 && nb != -2147483648)
	{
		mod = (nb / div) + '0';
		nb = nb % div;
		div = div / 10;
		write(1, &mod, 1);
	}
}

// int	main(void)
// {
// 	ft_putnbr(21311170);
// 	ft_putnbr(136138567);
// 	return (0);
// }

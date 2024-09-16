/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:34:51 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/16 11:42:01 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_comb(void)
{
	char	dig1;
	char	dig2;
	char	dig3;

	dig1 = '0';
	while (dig1 <= '7')
	{
		dig2 = dig1;
		while (++dig2 <= '8')
		{
			dig3 = dig2;
			while (++dig3 <= '9')
			{
				write(1, &dig1, 1);
				write(1, &dig2, 1);
				write(1, &dig3, 1);
				if (dig1 < '7')
				{
					write(1, ",", 1);
					write(1, " ", 1);
				}
			}
		}
		dig1++;
	}
}

// int main()
// {
// 	ft_print_comb();
// }
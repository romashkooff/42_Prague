/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:07:48 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/10 15:19:01 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	write_str(char *buffer, int i, int j)
{
	buffer[0] = i / 10 + '0';
	buffer[1] = i % 10 + '0';
	buffer[2] = ' ';
	buffer[3] = j / 10 + '0';
	buffer[4] = j % 10 + '0';
	if (i == 98 && j == 99)
	{
		write(1, buffer, 5);
	}
	else
	{
		buffer[5] = ',';
		buffer[6] = ' ';
		write(1, buffer, 7);
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	buffer[7];

	i = 0;
	j = 1;
	while (i < 99)
	{
		while (j < 100)
		{
			write_str(buffer, i, j);
			j++;
		}
		i++;
		j = i + 1;
	}
}

// int main()
// {
// 	ft_print_comb2();
// }
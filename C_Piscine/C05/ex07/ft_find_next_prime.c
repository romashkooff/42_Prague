/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:51:47 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/18 22:13:49 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	while (1)
	{
		i = 2;
		while (i * i <= nb)
		{
			if (nb % i == 0)
				break ;
			i++;
		}
		if (i * i > nb)
			return (nb);
		nb++;
	}
}

// int	main(void)
// {
// 	ft_find_next_prime(4);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:17:46 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/15 22:06:09 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	base;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	base = nb;
	while (power != 1)
	{
		nb = nb * base;
		power--;
	}
	return (nb);
}

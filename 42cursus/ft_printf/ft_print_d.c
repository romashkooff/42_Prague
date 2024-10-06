/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:11:58 by romashko          #+#    #+#             */
/*   Updated: 2024/10/06 12:36:52 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int decimal)
{
	int	count;

	count = 0;
	if (decimal < 0)
	{
		count += ft_print_c('-');
		decimal = -decimal;
	}
	if (decimal > 9)
	{
		ft_print_d(decimal / 10);
	}
	count += ft_print_c((decimal % 10) + '0');
	return (count);
}

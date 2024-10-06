/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:11:46 by romashko          #+#    #+#             */
/*   Updated: 2024/10/06 22:54:19 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexptr(unsigned long int ptr)
{
	long unsigned int	count;
	char				*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (ptr >= ft_strlen(hex))
	{
		count += ft_print_hexptr(ptr / ft_strlen(hex));
	}
	count += ft_print_c(hex[ptr % ft_strlen(hex)]);
	return (count);
}

int	ft_print_p(unsigned long int ptr)
{
	long unsigned int	count;

	if (ptr == 0)
	{
		ft_print_s("(nil)");
		return (5);
	}
	count = 0;
	count += ft_print_s("0x");
	count += ft_print_hexptr(ptr);
	return (count);
}

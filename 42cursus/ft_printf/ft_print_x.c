/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:12:26 by romashko          #+#    #+#             */
/*   Updated: 2024/10/06 22:15:32 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int decimal, const char format)
{
	char			*hex;
	unsigned int	count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	if (decimal >= ft_strlen(hex))
	{
		count += ft_print_x(decimal / ft_strlen(hex), format);
	}
	count += ft_print_c(hex[decimal % ft_strlen(hex)]);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:57:17 by romashko          #+#    #+#             */
/*   Updated: 2024/10/06 12:45:03 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_print_c(va_arg(args, int));
	else if (format == 's')
		count += ft_print_s(va_arg(args, char *));
	// else if (format == 'p')
	// 	count += ft_print_p(va_arg(args, unsigned long int));
	else if (format == 'd' || format == 'i')
		count += ft_print_d(va_arg(args, int));
	// else if (format == 'u')
	// 	count += ft_print_d(va_arg(args, unsigned int));
	// else if (format == 'x' || format == 'X')
	// 	count += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_print_c(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_format(args, format[++i]);
		else
			count += ft_print_c(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf(" %d ", 10);
	ft_printf(" %d ", 11);
	ft_printf(" %d ", 15);
	ft_printf(" %d ", 16);
	ft_printf(" %d ", 17);
	ft_printf(" %d ", 99);
	ft_printf(" %d ", 100);
	ft_printf(" %d ", 101);
	printf("\nThe end of program.");
}

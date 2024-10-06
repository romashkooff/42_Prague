/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:57:17 by romashko          #+#    #+#             */
/*   Updated: 2024/10/06 22:54:43 by romashko         ###   ########.fr       */
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
	else if (format == 'p')
		count += ft_print_p(va_arg(args, unsigned long int));
	else if (format == 'd' || format == 'i')
		count += ft_print_d(va_arg(args, int));
	else if (format == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_print_x(va_arg(args, unsigned int), format);
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

// int	main(void)
// {
// 	ft_printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	ft_printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
// 	printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
// }

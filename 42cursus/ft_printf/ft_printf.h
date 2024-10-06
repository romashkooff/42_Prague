/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:43:33 by romashko          #+#    #+#             */
/*   Updated: 2024/10/06 10:28:53 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list args, const char format);
int	ft_print_c(int c);
int	ft_print_s(char *str);
int	ft_print_p(unsigned long int ptr);
int	ft_print_d(int decimal);
int	ft_print_u(unsigned int un_decimal);
int	ft_print_x(unsigned int decimal, const char format);

#endif
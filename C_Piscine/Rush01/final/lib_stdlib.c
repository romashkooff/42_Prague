/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stdlib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:35:56 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 01:09:53 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skip.h"
#include "lib_ctype.h"

int	ft_atoi(const char *str)
{
	int	retval;
	int	sign;

	retval = 0;
	sign = 1;
	ft_skip_ws(&str);
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
		{
			sign *= -1;
		}
	}
	while (ft_isdigit(*str))
	{
		retval = retval * 10 + (sign * (*str++ - '0'));
	}
	return (retval);
}

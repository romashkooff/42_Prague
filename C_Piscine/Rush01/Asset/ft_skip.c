/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:33:04 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 00:45:59 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ctype.h"

void	ft_skip_ws(const char **str)
{
	while (ft_isspace(**str))
	{
		*str += 1;
	}
}

void	ft_skip_digits(const char **str)
{
	while (ft_isdigit(**str))
	{
		*str += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:06:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 00:23:56 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ctype.h"

#define OUT	0
#define IN	1

int	ft_count_words(const char *str)
{
	int	cnt;
	int	state;

	cnt = 0;
	state = OUT;
	while (*str != '\0')
	{
		if (!ft_isspace(*str++))
		{
			if (state == OUT)
				cnt++;
			state = IN;
		}
		else
			state = OUT;
	}
	return (cnt);
}

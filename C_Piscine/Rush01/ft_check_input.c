/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:20:23 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 01:10:06 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_count_words.h"
#include "ft_skip.h"
#include "lib_stdlib.h"
#include "lib_ctype.h"

int	ft_check_input(const char *input)
{
	int	words_cnt;
	int	words_cnt_side;
	int	got_ones;
	int	num;

	words_cnt = ft_count_words(input);
	if (words_cnt % 4 != 0)
		return (0);
	words_cnt_side = (words_cnt / 4);
	got_ones = 0;
	while (*input != '\0')
	{
		num = ft_atoi(input);
		if (!(num >= 1 && num <= words_cnt_side))
			return (0);
		else if (num == 1)
			got_ones++;
		ft_skip_ws(&input);
		ft_skip_digits(&input);
		if (!ft_isspace(*input) && !ft_isdigit(*input) && *input != '\0')
			return (0);
	}
	if (!(got_ones >= 2))
		return (0);
	return (1);
}

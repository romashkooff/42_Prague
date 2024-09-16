/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_possible_values.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 01:33:44 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 02:24:10 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_allocate_mem_for_possible_values.h"
#include "ft_skip.h"
#include "lib_stdlib.h"

#define TOP	1
#define BOTTOM	2
#define LEFT	3
#define RIGHT	4

/* TODO */
void	ft_process_args_side(char ***possible_values, const int WHICH_SIDE,
		int args_side_cnt, const char **args)
{
}

void	ft_process_args(char ***possible_values,
		int args_side_cnt, const char **args)
{
	ft_process_args_side(possible_values, TOP, args_side_cnt, args);
	ft_process_args_side(possible_values, BOTTOM, args_side_cnt, args);
	ft_process_args_side(possible_values, LEFT, args_side_cnt, args);
	ft_process_args_side(possible_values, RIGHT, args_side_cnt, args);
}

char	***ft_prepare_possible_values(int args_side_cnt, const char *args)
{
	char	***possible_values;

	possible_values = ft_allocate_mem_for_possible_values(args_side_cnt);
	if (possible_values == NULL)
		return (NULL);
	return (possible_values);
}

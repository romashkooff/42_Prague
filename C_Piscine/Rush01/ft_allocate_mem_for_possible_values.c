/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_mem_for_possible_values.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 01:33:44 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 02:06:33 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_amfpvs3_helper(int args_side_cnt, char ***buff, int x, int y)
{
	int	i;
	int	j;
	int	j_until;

	i = 0;
	while (i < x)
	{
		j = 0;
		if (i == x - 1)
			j_until = y;
		else
			j_until = args_side_cnt;
		while (j < j_until)
		{
			free(*(*(buff + i) + j));
		}
		free(*(buff + i));
	}
	free(buff);
}

char	***ft_allocate_mem_for_possible_values_stage_3(int args_side_cnt,
		char ***buff)
{
	int	x;
	int	y;

	x = 0;
	while (x < args_side_cnt)
	{
		y = 0;
		while (y < args_side_cnt)
		{
			*(*(buff + x) + y) = (char *) malloc(args_side_cnt + 1);
			if (*(*(buff + x) + y) == NULL)
				ft_amfpvs3_helper(args_side_cnt, buff, x, y);
			return (NULL);
		}
	}
	return (buff);
}

char	***ft_allocate_mem_for_possible_values_stage_2(int args_side_cnt,
		char ***buff)
{
	int	x;
	int	i;

	x = 0;
	while (x < args_side_cnt)
	{
		*(buff + x) = (char **) malloc(args_side_cnt * sizeof(char *));
		if (*(buff + x) == NULL)
		{
			i = 0;
			while (i < x)
				free(*(buff + i++));
			free(buff);
			return (NULL);
		}
	}
	return (ft_allocate_mem_for_possible_values_stage_3(args_side_cnt, buff));
}

char	***ft_allocate_mem_for_possible_values(int args_side_cnt)
{
	char	***buff;

	buff = (char ***) malloc(args_side_cnt * sizeof(char **));
	if (buff == NULL)
		return (NULL);
	return (ft_allocate_mem_for_possible_values_stage_2(args_side_cnt, buff));
}

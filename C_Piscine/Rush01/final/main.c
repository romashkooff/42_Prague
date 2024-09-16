/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:04:33 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 18:18:14 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_check_input.h"
#include "lib_string.h"
#include "ft_count_words.h"

#define ERROR_MSG	"Error\n"

#define INVALID_ARGS	1

#define MAX_MAP_SIZE	9

int	main(int argc, char **argv)
{
	int	args_side_cnt;
	int	candidates[

	if (!(argc > 1) || !ft_check_input(*(++argv)))
	{
		write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
		return (INVALID_ARGS);
	}
	args_side_cnt = (ft_count_words(*argv) / 4);
	possible_values = ft_prepare_possible_values(args_side_cnt, *argv);
	return (0);
}

#define N 4

void	apply_top_clues(int candidates[N][N][N], int clues[N]);
void	apply_bottom_clues(int candidates[N][N][N], int clues[N]);
void	apply_left_clues(int candidates[N][N][N], int clues[N]);
void	apply_right_clues(int candidates[N][N][N], int clues[N]);
void	find_and_apply_clue_special_cases(int candidates[N][N][N], int clues[N][N]);
#include <stdio.h>

int	solve(int grid[N][N], int clues[4][N], const int candidates[N][N][N],
		int row, int col);

void	print_grid(int grid[N][N]);

int	main(void)
{
	int clues[N][N] = {{3, 2, 1, 2}, {1, 2, 2, 3}, {3,2,2,1}, {2,1,2,3}};
	int candidates[N][N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				candidates[i][j][k] = k + 1;
		}
	}
	apply_top_clues(candidates, clues[0]);
	apply_bottom_clues(candidates, clues[1]);
	apply_left_clues(candidates, clues[2]);
	apply_right_clues(candidates, clues[3]);
	find_and_apply_clue_special_cases(candidates, clues);
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			printf("Cell (%d, %d): ", row, col);
			for (int num = 0; num < N; num++)
			{
				if (candidates[row][col][num] != 0)
				{
					printf("%d ", candidates[row][col][num]);
				}
			}
			printf("\n");
		}
	}
	int grid[N][N] = {0};
	solve(grid, clues, candidates, 0, 0);
	print_grid(grid);
}

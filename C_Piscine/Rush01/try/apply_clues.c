/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:20:05 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/18 15:35:05 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define N 6

// Function to remove a specific candidate value from a cell
void	remove_candidate(int candidates[N][N][N], int row, int col, int value)
{
	if (value >= 1 && value <= N)
	{
		candidates[row][col][value - 1] = 0;
	}
}

int	get_max_value_for_clue(int clue)
{
	if (clue >= 1 && clue <= N)
	{
		return (N - (clue - 1));
	}
	return (N);
}

// Function to apply top clues and remove candidates from the first row
void	apply_top_clues(int candidates[N][N][N], int clues[N])
{
	int	max_value;
	int	col;
	int	num;

	col = 0;
	while (col < N)
	{
		max_value = get_max_value_for_clue(clues[col]);
		num = max_value + 1;
		while (num <= N)
		{
			remove_candidate(candidates, 0, col, num);
			num++;
		}
		col++;
	}
}

// Function to apply bottom clues to the last row of the grid
void	apply_bottom_clues(int candidates[N][N][N], int clues[N])
{
	int	max_value;
	int	col;
	int	num;

	col = 0;
	while (col < N)
	{
		max_value = get_max_value_for_clue(clues[col]);
		num = max_value + 1;
		while (num <= N)
		{
			remove_candidate(candidates, N - 1, col, num);
			num++;
		}
		col++;
	}
}

// Function to apply left clues to the first column of the grid
void	apply_left_clues(int candidates[N][N][N], int clues[N])
{
	int	max_value;
	int	row;
	int	num;

	row = 0;
	while (row < N)
	{
		max_value = get_max_value_for_clue(clues[row]);
		num = max_value + 1;
		while (num <= N)
		{
			remove_candidate(candidates, row, 0, num);
			num++;
		}
		row++;
	}
}

// Function to apply right clues to the last column of the grid
void	apply_right_clues(int candidates[N][N][N], int clues[N])
{
	int	max_value;
	int	row;
	int	num;

	row = 0;
	while (row < N)
	{
		max_value = get_max_value_for_clue(clues[row]);
		num = max_value + 1;
		while (num <= N)
		{
			remove_candidate(candidates, row, N - 1, num);
			num++;
		}
		row++;
	}
}

int	main(void)
{
	int	candidates[N][N][N];

	// Initialize candidates with all possibilities (1 to N) in every cell
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			for (int num = 0; num < N; num++)
			{
				candidates[row][col][num] = num + 1; // Initialize with 1 to N
			}
		}
	}
	int clues[4][N] = {
		{5, 2, 1, 2, 4, 3}, // Top clues
		{1, 4, 3, 2, 2, 5}, // Bottom clues
		{4, 2, 3, 3, 2, 1}, // Left clues
		{2, 5, 1, 4, 3, 2}  // Right clues
	};
	apply_top_clues(candidates, clues[0]);
	apply_bottom_clues(candidates, clues[1]);
	apply_left_clues(candidates, clues[2]);
	apply_right_clues(candidates, clues[3]);
	// Print the candidates after applying the clues
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
	return (0);
}

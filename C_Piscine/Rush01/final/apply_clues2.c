/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_clues2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlyshchu <hlyshchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:20:05 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/18 18:33:18 by hlyshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define N 4

// Function prototypes
void	remove_candidate(int candidates[N][N][N], int row, int col, int value);
void	handle_clue_one(int candidates[N][N][N], int row, int col);
void	handle_clue_N_row(int candidates[N][N][N], int row, int ascending);
void	handle_clue_N_column(int candidates[N][N][N], int col, int ascending);
void	find_and_apply_clue_one(int candidates[N][N][N], int clues[4][N]);
void	handle_clue_one(int candidates[N][N][N], int row, int col);

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

// Function to handle clue == N for rows (left or right clues)
void	handle_clue_N_row(int candidates[N][N][N], int row, int ascending)
{
	int	value;
	int	num;
	int	col;

	if (ascending)
	{
		col = 0;
		while (col < N)
		{
			value = col + 1;
			num = 1;
			while (num <= N)
			{
				if (num != value)
					remove_candidate(candidates, row, col, num);
				num++;
			}
			col++;
		}
	}
	else
	{
		col = 0;
		while (col < N)
		{
			value = N - col;
			num = 1;
			while (num <= N)
			{
				if (num != value)
					remove_candidate(candidates, row, col, num);
				num++;
			}
			col++;
		}
	}
}

// Function to handle clue == N for columns (top or bottom clues)
void	handle_clue_N_column(int candidates[N][N][N], int col, int ascending)
{
	int	value;
	int	row;
	int	num;

	row = 0;
	if (ascending)
	{
		while (row < N)
		{
			value = row + 1;
			num = 1;
			while (num <= N)
			{
				if (num != value)
					remove_candidate(candidates, row, col, num);
				num++;
			}
			row++;
		}
	}
	else
	{
		while (row < N)
		{
			value = N - row;
			num = 1;
			while (num <= N)
			{
				if (num != value)
					remove_candidate(candidates, row, col, num);
				num++;
			}
			row++;
		}
	}
}

// Function to find special cases and apply specific handling
void	find_and_apply_clue_special_cases(int candidates[N][N][N],
		int clues[4][N])
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < N)
	{
		if (clues[0][col] == 1)
			handle_clue_one(candidates, 0, col);
		else if (clues[0][col] == N)
			handle_clue_N_column(candidates, col, 1);
		col++;
	}
	while (col < N)
	{
		if (clues[1][col] == 1)
			handle_clue_one(candidates, N - 1, col);
		else if (clues[1][col] == N)
			handle_clue_N_column(candidates, col, 0);
		col++;
	}
	while (row < N)
	{
		if (clues[2][row] == 1)
			handle_clue_one(candidates, row, 0);
		else if (clues[2][row] == N)
			handle_clue_N_row(candidates, row, 1);
		row++;
	}
	while (row < N)
	{
		if (clues[3][row] == 1)
			handle_clue_one(candidates, row, N - 1);
		else if (clues[3][row] == N)
			handle_clue_N_row(candidates, row, 0);
		row++;
	}
}

void	handle_clue_one(int candidates[N][N][N], int row, int col)
{
	int	num;
	int	c;
	int	r;

	num = 1;
	c = 0;
	r = 0;
	while (num < N)
	{
		remove_candidate(candidates, row, col, num);
		num++;
	}
	while (c < N)
	{
		if (c != col)
			remove_candidate(candidates, row, c, N);
		c++;
	}
	while (r < N)
	{
		if (r != row)
			remove_candidate(candidates, r, col, N);
		r++;
	}
}

/*
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
	// Example clues for a 6x6 grid
	int clues[4][N] = {
		{4,3,2,1}, // Top clues
		{1,2,2,2}, // Bottom clues
		{4,3,2,1}, // Left clues
		{1,2,2,2},  // Right clues
	};
	// Find all clues with value of 1 and apply the handle_clue_one() function
	apply_top_clues(candidates, clues[0]);
	apply_bottom_clues(candidates, clues[1]);
	apply_left_clues(candidates, clues[2]);
	apply_right_clues(candidates, clues[3]);
	find_and_apply_clue_special_cases(candidates, clues);
	// Print the candidates after applying the clue handling for 1s
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
 */

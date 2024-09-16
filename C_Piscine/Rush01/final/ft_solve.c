/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlyshchu <hlyshchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:25:12 by hlyshchu          #+#    #+#             */
/*   Updated: 2024/08/18 17:35:31 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	check_top_visibility(int grid[N][N], int clues[N]);
int	check_bottom_visibility(int grid[N][N], int clues[N]);
int	check_left_visibility(int grid[N][N], int clues[N]);
int	check_right_visibility(int grid[N][N], int clues[N]);
int	check_visibility(int grid[N][N], int clues[4][N]);
#include <stdbool.h>
//bool is_valid(int grid[N][N], int row, int col, int num);
int is_valid(int n, int array[N][N]);

// Backtracking function to solve the puzzle
int	solve(int grid[N][N], int clues[4][N], const int candidates[N][N][N],
		int row, int col)
{
	int	num;

	if (row == N)// If we reach the end of the grid
	{
		return (check_visibility(grid, clues));
	}
	if (col == N) // Move to the next row if we've finished the current one
	{
		return (solve(grid, clues, candidates, row + 1, 0));
	}
	num = 0; // Try placing numbers 1 to N in the cell
	while (num < N)
	{
		if (!candidates[row][col][num])
		{
			num++;
			continue ;
		}
		if (is_valid(N, grid))
		{
			grid[row][col] = num + 1;
			if (solve(grid, clues, candidates, row, col + 1)) // Recurse to the next cell
			{
				return (1); // Found a solution
			}
			grid[row][col] = 0; // Backtrack if placing the number doesn't lead to a solution
		}
		num++; // Increment number for the next iteration
	}
	return (0); // No solution found
}

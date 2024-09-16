/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce_candidates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlyshchu <hlyshchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:34:45 by hlyshchu          #+#    #+#             */
/*   Updated: 2024/08/18 11:44:23 by hlyshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define N 5  // Example grid size

// Function declarations
void initialize_candidates(int candidates[N][N][N]);
void apply_top_clues(int candidates[N][N][N], int clues[N]);
void apply_bottom_clues(int candidates[N][N][N], int clues[N]);
void apply_left_clues(int candidates[N][N][N], int clues[N]);
void apply_right_clues(int candidates[N][N][N], int clues[N]);
void propagate_constraints(int candidates[N][N][N], int clues[4][N]);
int backtrack(int grid[N][N], int candidates[N][N][N], int row, int col);
void print_grid(int grid[N][N]);
int check_visibility(int grid[N][N], int clues[4][N]);

// Function to initialize the candidates array with all possibilities
void initialize_candidates(int candidates[N][N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            for (int num = 0; num < N; num++) {
                candidates[row][col][num] = num + 1;  // Initialize with 1 to N
            }
        }
    }
}

// Function to apply top clue constraints
void apply_top_clues(int candidates[N][N][N], int clues[N]) {
    for (int col = 0; col < N; col++) {
        int visible_buildings = clues[col];
        if (visible_buildings == 1) {
            candidates[0][col][0] = N; // Place tallest building (N) at the top
            for (int i = 1; i < N; i++) {
                candidates[0][col][i] = 0; // Only the tallest building remains
            }
        } else if (visible_buildings == N) {
            // If the clue is N, buildings must be in descending order
            for (int row = 0; row < N; row++) {
                candidates[row][col][0] = N - row;
                for (int i = 1; i < N; i++) {
                    candidates[row][col][i] = 0; // Remove other possibilities
                }
            }
        }
    }
}

// Function to apply bottom clue constraints
void apply_bottom_clues(int candidates[N][N][N], int clues[N]) {
    for (int col = 0; col < N; col++) {
        int visible_buildings = clues[col];
        if (visible_buildings == 1) {
            candidates[N-1][col][0] = N; // Place tallest building at the bottom
            for (int i = 1; i < N; i++) {
                candidates[N-1][col][i] = 0; // Only the tallest building remains
            }
        } else if (visible_buildings == N) {
            // If the clue is N, buildings must be in descending order
            for (int row = N-1; row >= 0; row--) {
                candidates[row][col][0] = N - (N - 1 - row);
                for (int i = 1; i < N; i++) {
                    candidates[row][col][i] = 0; // Remove other possibilities
                }
            }
        }
    }
}

// Function to apply left clue constraints
void apply_left_clues(int candidates[N][N][N], int clues[N]) {
    for (int row = 0; row < N; row++) {
        int visible_buildings = clues[row];
        if (visible_buildings == 1) {
            candidates[row][0][0] = N; // Place tallest building on the left
            for (int i = 1; i < N; i++) {
                candidates[row][0][i] = 0; // Only the tallest building remains
            }
        } else if (visible_buildings == N) {
            // If the clue is N, buildings must be in descending order
            for (int col = 0; col < N; col++) {
                candidates[row][col][0] = N - col;
                for (int i = 1; i < N; i++) {
                    candidates[row][col][i] = 0; // Remove other possibilities
                }
            }
        }
    }
}

// Function to apply right clue constraints
void apply_right_clues(int candidates[N][N][N], int clues[N]) {
    for (int row = 0; row < N; row++) {
        int visible_buildings = clues[row];
        if (visible_buildings == 1) {
            candidates[row][N-1][0] = N; // Place tallest building on the right
            for (int i = 1; i < N; i++) {
                candidates[row][N-1][i] = 0; // Only the tallest building remains
            }
        } else if (visible_buildings == N) {
            // If the clue is N, buildings must be in descending order
            for (int col = N-1; col >= 0; col--) {
                candidates[row][col][0] = N - (N - 1 - col);
                for (int i = 1; i < N; i++) {
                    candidates[row][col][i] = 0; // Remove other possibilities
                }
            }
        }
    }
}

// Function to propagate constraints from all sides (top, bottom, left, right)
void propagate_constraints(int candidates[N][N][N], int clues[4][N]) {
    // Apply constraints from top
    apply_top_clues(candidates, clues[0]);
    
    // Apply constraints from bottom
    apply_bottom_clues(candidates, clues[1]);
    
    // Apply constraints from left
    apply_left_clues(candidates, clues[2]);
    
    // Apply constraints from right
    apply_right_clues(candidates, clues[3]);
}

// Function to backtrack and solve the puzzle using the candidates array
int backtrack(int grid[N][N], int candidates[N][N][N], int clues[4][N], int row, int col) {
    // If we reached the end of the grid, check the visibility and return
    if (row == N) {
        return check_visibility(grid, clues);
    }

    // Move to the next row if we've finished the current one
    if (col == N) {
        return backtrack(grid, candidates, clues, row + 1, 0);
    }

    // Skip already determined cells (if only one candidate exists)
    int num_candidates = 0;
    int value = -1;
    for (int i = 0; i < N; i++) {
        if (candidates[row][col][i] != 0) {
            num_candidates++;
            value = candidates[row][col][i];
        }
    }
    if (num_candidates == 1) {
        grid[row][col] = value;  // Fixed value
        return backtrack(grid, candidates, clues, row, col + 1);
    } else if (num_candidates == 0) {
        return 0; // No valid solution
    }

    // Try placing numbers from the candidates array
    for (int i = 0; i < N; i++) {
        if (candidates[row][col][i] != 0) {
            grid[row][col] = candidates[row][col][i];

            if (backtrack(grid, candidates, clues, row, col + 1)) {
                return 1;  // Solution found
            }

            // Backtrack: Undo the placement
            grid[row][col] = 0;
        }
    }

    return 0; // No solution found
}


int	check_top_visibility(int grid[N][N], int clues[N])
{
	int	row;
	int	col;
	int	max_height;
	int	visible_count;

	col = 0;
	while (col < N)
	{
		max_height = 0;
		visible_count = 0;
		row = 0;
		while (row < N)
		{
			if (grid[row][col] > max_height)
			{
				max_height = grid[row][col];
				visible_count++;
			}
			row++;
		}
		if (visible_count != clues[col])
			return (0); // Clues for top are not satisfied
		col++;
	}
	return (1); // All top clues satisfied
}

// Function to check visibility from the bottom
int	check_bottom_visibility(int grid[N][N], int clues[N])
{
	int	row;
	int	col;
	int	max_height;
	int	visible_count;

	col = 0;
	while (col < N)
	{
		max_height = 0;
		visible_count = 0;
		row = N - 1;
		while (row >= 0)
		{
			if (grid[row][col] > max_height)
			{
				max_height = grid[row][col];
				visible_count++;
			}
			row--;
		}
		if (visible_count != clues[col])
			return (0); // Clues for bottom are not satisfied
		col++;
	}
	return (1); // All bottom clues satisfied
}

// Function to check visibility from the left
int	check_left_visibility(int grid[N][N], int clues[N])
{
	int	row;
	int	col;
	int	max_height;
	int	visible_count;

	row = 0;
	while (row < N)
	{
		max_height = 0;
		visible_count = 0;
		col = 0;
		while (col < N)
		{
			if (grid[row][col] > max_height)
			{
				max_height = grid[row][col];
				visible_count++;
			}
			col++;
		}
		if (visible_count != clues[row])
			return (0); // Clues for left are not satisfied
		row++;
	}
	return (1); // All left clues satisfied
}

// Function to check visibility from the right
int	check_right_visibility(int grid[N][N], int clues[N])
{
	int	row;
	int	col;
	int	max_height;
	int	visible_count;

	row = 0;
	while (row < N)
	{
		max_height = 0;
		visible_count = 0;
		col = N - 1;
		while (col >= 0)
		{
			if (grid[row][col] > max_height)
			{
				max_height = grid[row][col];
				visible_count++;
			}
			col--;
		}
		if (visible_count != clues[row])
			return (0); // Clues for right are not satisfied
		row++;
	}
	return (1); // All right clues satisfied
}

int	solve(int grid[N][N], int clues[4][N], int row, int col)
{
	int	num;

	if (row == N)// If we reach the end of the grid
	{
		return (check_visibility(grid, clues));
	}
	if (col == N) // Move to the next row if we've finished the current one
	{
		return (solve(grid, clues, row + 1, 0));
	}
	num = 1; // Try placing numbers 1 to N in the cell
	while (num <= N)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, row, col + 1)) // Recurse to the next cell
			{
				return (1); // Found a solution
			}
			grid[row][col] = 0; // Backtrack if placing the number doesn't lead to a solution
		}
		num++; // Increment number for the next iteration
	}
	return (0); // No solution found
}

// Main visibility check function
int	check_visibility(int grid[N][N], int clues[4][N])
{
	if (!check_top_visibility(grid, clues[0]))
		return (0);
	if (!check_bottom_visibility(grid, clues[1]))
		return (0);
	if (!check_left_visibility(grid, clues[2]))
		return (0);
	if (!check_right_visibility(grid, clues[3]))
		return (0);
	return (1);
}

int main() {
    int grid[N][N] = {0};  // Initialize the grid to 0

    // Example clues for a 5x5 puzzle: Top, Bottom, Left, Right
    int clues[4][N] = {
        {4, 2, 1, 2, 3},  // Top clues
        {1, 4, 3, 2, 2},  // Bottom clues
        {3, 2, 3, 2, 1},  // Left clues
        {3, 4, 1, 2, 2}   // Right clues
    };

    // Create a candidates array with all possibilities
    int candidates[N][N][N];
    initialize_candidates(candidates);

    // Propagate initial constraints based on the clues
    propagate_constraints(candidates, clues);

    // Solve the puzzle using backtracking and constraint propagation
    if (backtrack(grid, candidates, clues, 0, 0)) {
        printf("Puzzle Solved!\n");
        print_grid(grid);  // Function to print the final grid
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

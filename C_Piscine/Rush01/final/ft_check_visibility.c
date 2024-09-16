#include <stdio.h>

#define N 4

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

int is_valid(int n, int array[N][N]);

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
	if (!is_valid(N, grid))
		return (0);
	return (1);
}

// Function to print the grid
void	print_grid(int grid[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

// Example usage
/*
int main() {
    int grid[N][N] = {
    {2,3,5,4,1},
    {1,5,4,3,2},
    {3,4,2,1,5},
    {4,2,1,5,3},
    {5,1,3,2,4}
};  // Initialize the grid to 0

    // Example clues for a 5x5 puzzle: Top, Bottom, Left, Right
    int clues[4][N] = {
        {4,2,1,2,3},  // Top clues
        {1,4,3,2,2},  // Bottom clues
        {3,2,3,2,1},  // Left clues
        {3,4,1,2,2}   // Right clues
    };

    // Check visibility with the current grid and clues
    if (check_visibility(grid, clues)) {
        printf("Visibility is valid.\n");
    } else {
        printf("Visibility is invalid.\n");
    }

    return 0;
}
*/

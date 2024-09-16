#include <stdio.h>
#include <stdbool.h>

#define N 5

// Function to check if placing the number at (row, col) is valid
bool is_valid(int grid[N][N], int row, int col, int num) {
    // Check if the number exists in the row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    return true;
}


bool check_visibility(int grid[N][N], int clues[N][N]) {
    // Check visibility from the top and bottom
    for (int col = 0; col < N; col++) {
        int max_height = 0, visible_count = 0;
        // From top
        for (int row = 0; row < N; row++) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visible_count++;
            }
        }
        if (visible_count != clues[0][col]) return false;

        // From bottom
        max_height = 0;
        visible_count = 0;
        for (int row = N - 1; row >= 0; row--) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visible_count++;
            }
        }
        if (visible_count != clues[1][col]) return false;
    }

    // Check visibility from the left and right
    for (int row = 0; row < N; row++) {
        int max_height = 0; 
        int visible_count = 0;
        // From left
        for (int col = 0; col < N; col++) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visible_count++;
            }
        }
        if (visible_count != clues[2][row]) return false;

        // From right
        max_height = 0;
        visible_count = 0;
        for (int col = N - 1; col >= 0; col--) {
            if (grid[row][col] > max_height) {
                max_height = grid[row][col];
                visible_count++;
            }
        }
        if (visible_count != clues[3][row]) return false;
    }

    return true;
}


// Backtracking function to solve the puzzle
bool solve(int grid[N][N], int clues[N][N], int row, int col) {
    // If we reach the end of the grid
    if (row == N) {
        return check_visibility(grid, clues);
    }

    // Move to the next row if we've finished the current one
    if (col == N) {
        return solve(grid, clues, row + 1, 0);
    }

    // Try placing numbers 1 to N in the cell
    for (int num = 1; num <= N; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve(grid, clues, row, col + 1)) {
                return true;
            }

            // Backtrack if placing the number doesn't lead to a solution
            grid[row][col] = 0;
        }
    }

    return false;
}

// Function to print the grid
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N] = {0};  // Initialize the grid to 0

    // Clues for the puzzle: Top, Bottom, Left, Right
    int clues[4][N] = {
        {4, 2, 1, 2, 3},  // Top clues
        {1, 4, 3, 2, 2},  // Bottom clues
        {3, 2, 3, 2, 1},  // Left clues
        {3, 4, 1, 2, 2}   // Right clues
    };

    // Solve the puzzle
    if (solve(grid, clues, 0, 0)) {
        printf("Solved Skyscraper Puzzle:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

#include <stdio.h>

#define N 4

int is_valid(int n, int array[N][N]) {
    int row_check[N + 1];  // To track the numbers in the row (1 to N, ignore 0)
    int col_check[N + 1];  // To track the numbers in the column (1 to N, ignore 0)

    // Check each row
    for (int i = 0; i < n; i++) {
        // Initialize the row check array
        for (int k = 1; k <= n; k++) {
            row_check[k] = 0;
        }

        // Validate row i
        for (int j = 0; j < n; j++) {
            int val = array[i][j];
            if (val != 0) {  // Ignore 0
                if (val < 1 || val > n || row_check[val] == 1) {
                    return 0;  // Duplicate or invalid number found in the row
                }
                row_check[val] = 1;
            }
        }
    }

    // Check each column
    for (int j = 0; j < n; j++) {
        // Initialize the column check array
        for (int k = 1; k <= n; k++) {
            col_check[k] = 0;
        }

        // Validate column j
        for (int i = 0; i < n; i++) {
            int val = array[i][j];
            if (val != 0) {  // Ignore 0
                if (val < 1 || val > n || col_check[val] == 1) {
                    return 0;  // Duplicate or invalid number found in the column
                }
                col_check[val] = 1;
            }
        }
    }

    return 1;  // All rows and columns are valid
}

// Function to check if placing the number at (row, col) is valid
/*
bool is_valid(int grid[N][N], int row, int col, int num) {
    // Check if the number exists in the row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    return true;
}
 */


/*
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
*/


// Function to print the grid
//
/*
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
 */

/*
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
 */

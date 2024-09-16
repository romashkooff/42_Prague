#include <stdio.h>

#define N 5

// Function to remove a specific candidate value from a cell
void remove_candidate(int candidates[N][N][N], int row, int col, int value) {
    candidates[row][col][value - 1] = 0;  // Remove the value from the candidates
}

// Function to apply top clues and remove impossible candidates
void apply_top_clues(int candidates[N][N][N], int clues[N]) {
    for (int col = 0; col < N; col++) {
        int clue = clues[col];  // Get the clue for this column

        // Clue == 1: The first cell must contain only the tallest building (N)
        if (clue == 1) {
            // Remove all values except for N (5 in this case)
            for (int num = 1; num < N; num++) {
                remove_candidate(candidates, 0, col, num);  // Only N should remain
            }
        }
        // For all other clues, remove the buildings that cannot be in the first row
        else {
            // Remove buildings taller than the clue
            for (int num = clue + 1; num <= N; num++) {
                remove_candidate(candidates, 0, col, num);  // Remove numbers greater than the clue
            }
        }
    }
}

// Example usage for testing
int main() {
    // Initialize candidates with all possibilities (1 to N) in every cell
    int candidates[N][N][N];
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            for (int num = 0; num < N; num++) {
                candidates[row][col][num] = num + 1;  // Initialize with 1 to N
            }
        }
    }

    // Example top clues for a 5x5 grid
    int top_clues[N] = {4, 2, 1, 2, 3};

    // Apply the top clues to remove invalid candidates
    apply_top_clues(candidates, top_clues);

    // Print the candidates after applying the top clues
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("Cell (%d, %d): ", row, col);
            for (int num = 0; num < N; num++) {
                if (candidates[row][col][num] != 0) {
                    printf("%d ", candidates[row][col][num]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}

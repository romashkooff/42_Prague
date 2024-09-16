#include <stdio.h>
#include <stdlib.h>
#include "apply_clues.h"
#include "candidates_init.h"

// #define N 5  // Example grid size
// void initialize_candidates(int candidates[N][N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++) {
//             for (int num = 0; num < N; num++) {
//                 candidates[row][col][num] = num + 1;  // Initialize with 1 to N
//             }
//         }
//     }
// }

// void print_candidates(int candidates[N][N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++) {
//             printf("Cell (%d, %d): ", row, col);
//             for (int num = 0; num < N; num++) {
//                 if (candidates[row][col][num] != 0) {
//                     printf("%d ", candidates[row][col][num]);
//                 }
//             }
//             printf("\n");
//         }
//     }
// }
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

    // Print the candidates for debugging
    print_candidates(candidates);

    // Further logic for solving the puzzle using backtracking will go here.

    return 0;
}

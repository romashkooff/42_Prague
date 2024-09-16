// apply_clues.h
#ifndef APPLY_CLUES_H
#define APPLY_CLUES_H

#define N 5

void apply_top_clues(int candidates[N][N][N], int clues[N]);
void apply_bottom_clues(int candidates[N][N][N], int clues[N]);
void apply_left_clues(int candidates[N][N][N], int clues[N]);
void apply_right_clues(int candidates[N][N][N], int clues[N]);
void propagate_constraints(int candidates[N][N][N], int clues[4][N]);
void remove_candidate(int candidates[N][N][N], int row, int col, int value);

#endif

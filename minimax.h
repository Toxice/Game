#ifndef MINIMAX_H
#define MINIMAX_H

#include "game.h"

/* Students implement classical minimax using only arrays & recursion. */

/* Evaluate best score for the current board.
   maximizing_player = PLAYER_AI (for example)
   current_player    = whose turn it is for this recursive call.
*/
int minimax(char board[BOARD_SIZE][BOARD_SIZE],
            char maximizing_player,
            char current_player);

/* Find best move for AI.
   Result is written through best_row, best_col (pointers).
*/
void find_best_move(char board[BOARD_SIZE][BOARD_SIZE],
                    char ai_player,
                    int *best_row,
                    int *best_col);

#endif

#include "minimax.h"

/* Helper to switch player */
static char other_player(char p)
{
    if (p == PLAYER_HUMAN)
        return PLAYER_AI;
    else
        return PLAYER_HUMAN;
}

/* You decide scoring convention
   e.g. +10 AI wins, -10 human wins, 0 draw.
*/
int minimax(char board[BOARD_SIZE][BOARD_SIZE],
            char maximizing_player,
            char current_player)
{
    /* TODO:
       1. Check winner using check_winner().
       2. If terminal state: return score.
       3. If current_player == maximizing_player:
            - try all valid moves
            - recursively call minimax(...)
            - keep the maximum score
          else (minimizing player):
            - keep the minimum score
       4. Undo moves after trying (set back to EMPTY).
    */

    return 0;
}

void find_best_move(char board[BOARD_SIZE][BOARD_SIZE],
                    char ai_player,
                    int *best_row,
                    int *best_col)
{
    /* TODO:
       Loop on all cells:
         - if move valid:
             - play move
             - call minimax(...)
             - undo move
             - keep best score and corresponding row/col
       Write result into *best_row and *best_col.
    */
}

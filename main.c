#include <stdio.h>
#include "game.h"
#include "minimax.h"

int main(void)
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player = PLAYER_HUMAN; /* Human starts */
    char winner = EMPTY;

    int row, col;

    init_board(board);

    printf("=== Tic-Tac-Toe with Minimax ===\n");
    printf("You are '%c', computer is '%c'\n\n", PLAYER_HUMAN, PLAYER_AI);

    while (1)
    {
        print_board(board);

        /* Check game end */
        winner = check_winner(board);
        if (winner == PLAYER_HUMAN)
        {
            printf("You win!\n");
            break;
        }
        else if (winner == PLAYER_AI)
        {
            printf("Computer wins!\n");
            break;
        }
        else if (is_board_full(board))
        {
            printf("Draw!\n");
            break;
        }

        if (current_player == PLAYER_HUMAN)
        {
            /* Human turn: read input and validate */
            do
            {
                printf("Your move (row col, 0-%d): ", BOARD_SIZE - 1);
                if (scanf("%d %d", &row, &col) != 2)
                {
                    /* Simple input reset, students can improve */
                    printf("Invalid input. Exiting.\n");
                    return 1;
                }
            } while (!is_move_valid(board, row, col));

            apply_move(board, row, col, PLAYER_HUMAN);
            current_player = PLAYER_AI;
        }
        else
        { /* AI turn */
            printf("Computer is thinking...\n");

            /* Students must implement find_best_move() with minimax */
            find_best_move(board, PLAYER_AI, &row, &col);

            printf("Computer plays: %d %d\n", row, col);
            apply_move(board, row, col, PLAYER_AI);
            current_player = PLAYER_HUMAN;
        }
    }

    print_board(board);
    printf("Game over.\n");

    return 0;
}

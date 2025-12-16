#include <stdio.h>
#include "game.h"

char game_board[BOARD_SIZE][BOARD_SIZE];

/**
 * @brief set all cells of the matrix to an empty cell (EMPTY = ' ')
 * @author Mor
 * @details we basically pass a pointer to the array (matrix at this case), since the array decays
    to a pointer, C can't know the array borders, we must know them ahead of time (thats why we have the BOARD_SIZE 
    constant in the #define) 
 */
void init_board(char game_board[BOARD_SIZE][BOARD_SIZE])
{
    int r,c;
    for(c = 0; c < BOARD_SIZE; c++) {
        for(r = 0; r < BOARD_SIZE; r++) {
            game_board[c][r] = EMPTY;
        }
    }
}

/**
 * @brief print the game board to the screen
 * @author Lecturer
 */
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int r, c;
    printf("\n");
    for (r = 0; r < BOARD_SIZE; r++)
    {
        for (c = 0; c < BOARD_SIZE; c++)
        {
            char cell = board[r][c];
            if (cell == EMPTY)
            {
                cell = ' ';
            }
            printf(" %c ", cell);
            if (c < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (r < BOARD_SIZE - 1)
        {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

/**
 * @brief check if our move is valid
 * @details before even placing our 'X', we verify the location we wish the place in is free, meaning - if its EMPTY
 */
int is_move_valid(char game_board[][BOARD_SIZE], int row_location, int col_location)
{
    if (0 < row_location < BOARD_SIZE && 0 < col_location < BOARD_SIZE) {
        if (game_board[row_location][col_location] == EMPTY) 
        {
            return 1; // TRUE
        }
    }
    return 0; // FALSE
}

/**
 * @brief set the player symbol at the desired locaation in the board
 * @details after verifying the location is free, we insert our player's symbol (X in that case)
 */
void apply_move(char game_board[][BOARD_SIZE], int row_location, int col_location) 
{
    /* TODO: assume move is valid and place player's symbol */
    int is_valid = is_move_valid(game_board, row_location, col_location);
    if (is_valid)
    {
        game_board[row_location][col_location] = 'X';
    }
}


/**
 * @brief checks if the game board is full
 * @details loop over the board, and check if the value is EMPTY, for the first cell who's empty -> break and return 0 (FALSE)
 * if all cells are non EMPTY -> return 1
 */
int is_board_full(char game_board[][BOARD_SIZE])
{
    /* TODO: return 1 if no EMPTY cells, else 0 */
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (game_board[row][col] == EMPTY) return 1;
        }
    }
    return 0;
}

char check_winner(args)
{
    /* TODO: check rows, columns, diagonals.
       Return PLAYER_HUMAN / PLAYER_AI / 'D' / EMPTY.
       Note: main() handles draw via is_board_full(), so 'D' is optional.
    */
}

/**
 * @brief checks if the player won at one of the rows of the board
 * @details return options:
 *              0 -> player won at row 0; 1 -> player won at row 1; 2 -> player won at row 2; (-1) -> player has'nt won at any row; 
 */
int is_player_winner_rows(char game_board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;
    char player_buffer[BOARD_SIZE];
    for (row = 0; row < BOARD_SIZE; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            player_buffer[col] = game_board[row][col];
        } if (player_buffer == "XXX") return col;
    }
    return -1;
}

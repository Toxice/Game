#include <stdio.h>
#include "game.h"
#include <limits.h>

char buffer[BOARD_SIZE] = {0};

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

/**\
 * @brief check for winn
 */
static int is_player_won_rows(char game_board[BOARD_SIZE][BOARD_SIZE]) 
{
    int row_verifier = INT_MAX;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        row_verifier = check_row(row, game_board);
        if (row_verifier != -1)
        {
            
        }
        
    }
    return -1;
}

/**
 * @brief check if there is a winner at some row
 * @details returns the number of the row if there is a winner, returns (-1) if there is'nt a winner
 */
static int check_row(int row, char[BOARD_SIZE][BOARD_SIZE])
{
    char buffer[BOARD_SIZE] = {0};
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        buffer[i] = game_board[row][i];
    } 
    if (!is_buffer_empty(buffer)) {
        return row;
    }
    return -1;
}

/**
 * @brief check if there is a winner at some row
 * @details returns the number of the row if there is a winner, returns (-1) if there is'nt a winner
 */
static int check_coloumn(int column, char[BOARD_SIZE][BOARD_SIZE])
{
    char buffer[BOARD_SIZE] = {0};
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        buffer[i] = game_board[i][column];
    } 
    if (!is_buffer_empty(buffer)) {
        return column;
    }
    return -1;
}


/**
 * @brief verify the buffer is empty
 */
static int is_buffer_empty(char buffer[BOARD_SIZE])
{
    if (buffer == "   ") return 1;
    return 0;
}

/**
 * @brief sets the buffer to the characters in that row
 */
static void set_buffer_at_row(char buffer[BOARD_SIZE], int row, char game_board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        buffer[i] = game_board[row][i];
    }
}

/**
 * @brief sets the buffer to the characters in that columnS
 */
static void set_buffer_at_coloum(char buffer[BOARD_SIZE], int column, char game_board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        buffer[i] = game_board[i][column];
    }
}

/**
 * @brief checks if the player won
 */
static int is_player_won(char buffer[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (buffer[i] != PLAYER_HUMAN)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief checks if the computer won
 */
static int is_AI_won(char buffer[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (buffer[i] != PLAYER_AI)
        {
            return 0;
        }
    }
    return 1;
}

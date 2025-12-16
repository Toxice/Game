#ifndef GAME_H
#define GAME_H

#define BOARD_SIZE 3

#define EMPTY ' '
#define PLAYER_HUMAN 'X'
#define PLAYER_AI 'O'

/* Game;
Replace args with the correct arguments*/
void init_board(char board_game[BOARD_SIZE][BOARD_SIZE]);

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);

int is_move_valid(char board_game[][], int row_location, int col_location);

void apply_move(char game_board[][BOARD_SIZE], int row_location, int col_location);

int is_board_full(char game_board[][BOARD_SIZE]);

char check_winner(args);

int is_player_winner_rows(char game_board[BOARD_SIZE][BOARD_SIZE]);

/* Return:
   PLAYER_HUMAN, PLAYER_AI, 'D' for draw, or EMPTY if no winner yet */

#endif

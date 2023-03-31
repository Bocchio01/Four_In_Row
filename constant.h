/*
 * This file declares the constants used in the program.
 * The constants are declared as extern so that they can be used in other files.
 * The constants are defined in the file constant.c
 */

#ifndef CONSTANT_H
#define CONSTANT_H

#define MAX_N_PLAYER 10
#define MAX_N_ROW 15
#define MAX_N_COL 15
#define EMPTY_CELL -1

#define PRINT_COLOURED(c, f, s) printf("\033[%dm" f "\033[0m", c, s)

struct board
{
    int n_row;
    int n_col;
    int n_win_symbol;
    int board[MAX_N_ROW][MAX_N_COL];
    int symbols[MAX_N_PLAYER];
    int colors[MAX_N_PLAYER];
};

struct current_move
{
    int row;
    int col;
};

struct game
{
    int n_player;
    int player_index;
    struct board board;
    char player_name[MAX_N_PLAYER][20];
    struct current_move current_move;
};

#endif

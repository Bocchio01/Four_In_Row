#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MAX_PLAYERS 6
#define MAX_ROWS 15
#define MAX_COLUMNS 15
#define MAX_WIN_SYMBOLS 10
#define EMPTY_CELL -1

#define PRINT_COLOURED(c, f, s) printf("\033[%dm" f "\033[0m", c, s)

typedef struct Board
{
    int numRows;
    int numCols;
    int numWinSymbols;
    int cells[MAX_ROWS][MAX_COLUMNS];
    int playerSymbols[MAX_PLAYERS];
    int playerColors[MAX_PLAYERS];
} board_t;

typedef struct Board_Index
{
    int row;
    int column;
} board_index_t;

typedef struct Game
{
    int numPlayers;
    int currentPlayerIndex;
    board_t *gameBoard;
    char playerName[MAX_PLAYERS][20];
    board_index_t *currentMove;
} game_t;

#endif
/*
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-04-01
 *
 * This file is part of the 'Connect 4 Game' project.
 * It contains the constants used in the game.
 *
 * License: MIT
 *
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MAX_PLAYERS 10
#define MAX_ROWS 15
#define MAX_COLUMNS 15
#define MAX_WIN_SYMBOLS 10
#define EMPTY_CELL -1

#define PRINT_COLOURED(c, f, s) printf("\033[%dm" f "\033[0m", c, s)

struct Board
{
    int numRows;
    int numCols;
    int numWinSymbols;
    int cells[MAX_ROWS][MAX_COLUMNS];
    int playerSymbols[MAX_PLAYERS];
    int playerColors[MAX_PLAYERS];
};

struct BoardCoordinates
{
    int row;
    int column;
};

struct Game
{
    int numPlayers;
    int currentPlayerIndex;
    struct Board gameBoard;
    char playerName[MAX_PLAYERS][20];
    struct BoardCoordinates currentMove;
};

#endif

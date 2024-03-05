/*
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-04-01
 *
 * This file is part of the 'Connect 4 Game' project.
 * The functions in this file are used to parse the command line arguments and to initialize the game->
 *
 * License: MIT
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "default.h"

#include "../definitions.h"

void C4G_Setup_Default(game_t *game)
{
    int defaultPlayerSymbols[] = {'x', 'o', '*', '@', '#', '$'};
    int defaultPlayerColors[] = {31, 33, 32, 34, 35, 36};

    game->numPlayers = 2;
    game->currentPlayerIndex = 0;
    game->currentMove->row = -1;
    game->currentMove->column = -1;
    game->gameBoard->numRows = 6;
    game->gameBoard->numCols = 7;
    game->gameBoard->numWinSymbols = 4;

    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        game->gameBoard->playerSymbols[i] = defaultPlayerSymbols[i];
        game->gameBoard->playerColors[i] = defaultPlayerColors[i];
    }
}
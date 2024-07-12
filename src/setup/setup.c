#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "setup.h"

#include "../definitions.h"
#include "default.h"
#include "cmd.h"
#include "../utils.h"

void C4G_Setup(game_t *game, int argc, char *argv[])
{

    if (argc == 1)
    {
        C4G_Setup_Default(game);
        C4G_Setup_Prompting(game);
    }
    else
    {
        C4G_Setup_Default(game);
        C4G_Setup_CMD(game, argc, argv);
    }

    for (int r = 0; r < game->gameBoard->numRows; r++)
        for (int c = 0; c < game->gameBoard->numCols; c++)
            game->gameBoard->cells[r][c] = EMPTY_CELL;

    srand((unsigned int)time(NULL));
    game->currentPlayerIndex = rand() % game->numPlayers;
    printf("\n%s starts! (press any key to continue)", game->playerName[game->currentPlayerIndex]);

    clear_input_buffer();
    getchar();
}

void C4G_Setup_Prompting(game_t *game)
{
    printf("Welcome to the 'Connect 4 Game' game!\n");
    printf("This program was developed by Tommaso Bocchietti back in 2017 at high school and updated in 2023.\n");

    print_horizontal_line(50, '-');

    for (int i = 0; i < game->numPlayers; i++)
    {
        printf("\nEnter the name of player %d: ", i + 1);
        // scanf("%s", &game->playerName[i]);
        printf("Player %s is going to use: ", game->playerName[i]);
        PRINT_COLOURED(game->gameBoard->playerColors[i], "%c\n", game->gameBoard->playerSymbols[i]);
    }

    print_horizontal_line(50, '-');

    printf("\nTo choose who starts, let's roll a dice");
    for (int i = 0; i < 5; i++)
    {
        delay(200);
        printf(".");
    }
}
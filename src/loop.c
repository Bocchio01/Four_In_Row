#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loop.h"
#include "definitions.h"
#include "functions.h"

void C4G_Loop(game_t *game)
{
    while (true)
    {

        game->currentMove->row = -1;
        game->currentMove->column = -1;
        draw_board(game->gameBoard);

        while (game->currentMove->row == -1)
        {
            printf("\n%s (", game->playerName[game->currentPlayerIndex]);
            PRINT_COLOURED(game->gameBoard->playerColors[game->currentPlayerIndex], "%c", game->gameBoard->playerSymbols[game->currentPlayerIndex]);
            printf(") selects any column from 1 to %d: ", game->gameBoard->numCols);
            while (scanf("%d", &game->currentMove->column) != 1)
            {
                printf("You can enter only integer values: ");
                scanf("%*s");
            }
            game->currentMove->column--; // Because of the array index from 0 to 6

            game->currentMove->row = insert_into_board(game->gameBoard, game->currentPlayerIndex, game->currentMove->column);
        };

        if (check_winner(game->gameBoard, game->currentMove))
        {
            draw_board(game->gameBoard);
            printf("\nCongratulations %s, you won! :)", game->playerName[game->currentPlayerIndex]);
            break;
        }

        if (check_tie(game->gameBoard))
        {
            draw_board(game->gameBoard);
            printf("\nOhoh, looks like the game ended in draw...");
            break;
        }

        game->currentPlayerIndex = (game->currentPlayerIndex + 1) % game->numPlayers;
    };
}
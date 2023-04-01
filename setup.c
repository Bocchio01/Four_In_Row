/*
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-04-01
 *
 * This file is part of the 'Connect 4 Game' project.
 * The functions in this file are used to parse the command line arguments and to initialize the game.
 *
 * License: MIT
 *
 */

#include "setup.h"
#include "utils.h"
#include "board.h"
#include "constant.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>

struct Game setupGame(int argc, char *argv[])
{
    // initialize values
    struct Game game = {
        .numPlayers = 2,
        .currentPlayerIndex = 0,
        .currentMove.row = -1,
        .currentMove.column = -1,
        .gameBoard.numRows = 6,
        .gameBoard.numCols = 7,
        .gameBoard.numWinSymbols = 4,
        .gameBoard.playerSymbols = {'x', 'o', '*', '@', '#', '$'},
        .gameBoard.playerColors = {31, 33, 32, 34, 35, 36},
    };

    // Parse command line arguments
    int c;
    int option_index = 0;
    static struct option long_options[] =
        {
            {"help", no_argument, 0, 'h'},
            {"board", required_argument, 0, 'b'},
            {"player", required_argument, 0, 'p'},
            {"winning", required_argument, 0, 'w'},
            {0, 0, 0, 0}};

    if (argc > 1)
    {
        while ((c = getopt_long(argc, argv, "hb:p:w:", long_options, &option_index)) != -1)
        {
            switch (c)
            {
            case 'h':
                printf("Usage: %s [options]\n", argv[0]);
                printf("Options:\n"
                       "-h, --help \t Show this help message and exit.\n"
                       "-b, --board \t Set the board size in the format 'rows x columns'. Default: 6x7.\n"
                       "-p, --player \t Set the number of players. Default: 2.\n"
                       "-w, --winning \t Set the number of symbols to win. Default: 4.\n");
                exit(0);

            case 'b':
                if (sscanf(optarg, "%ux%u", &game.gameBoard.numRows, &game.gameBoard.numCols) != 2)
                {
                    printf("Invalid board size: %s\n", optarg);
                    exit(1);
                }
                break;

            case 'p':
                if (sscanf(optarg, "%u", &game.numPlayers) != 1)
                {
                    printf("Invalid number of player: %s\n", optarg);
                    exit(1);
                }
                break;

            case 'w':
                if (sscanf(optarg, "%u", &game.gameBoard.numWinSymbols) != 1)
                {
                    printf("Invalid number of symbols to win: %s\n", optarg);
                    exit(1);
                }
                break;

            default:
                printf("Unknown argument: %c %s\n", c, optarg);
                exit(1);
            }
        }

        if (game.gameBoard.numRows < 4 || game.gameBoard.numRows > MAX_ROWS)
        {
            printf("Invalid number of row: %u (must be between 4 and %d)\n", game.gameBoard.numRows, MAX_ROWS);
            exit(1);
        }
        else if (game.gameBoard.numCols < 4 || game.gameBoard.numCols > MAX_COLUMNS)
        {
            printf("Invalid number of column: %u (must be between 4 and %d)\n", game.gameBoard.numCols, MAX_COLUMNS);
            exit(1);
        }

        if (game.numPlayers < 2 || game.numPlayers > MAX_PLAYERS)
        {
            printf("Invalid number of player: %u (must be between 2 and %d)\n", game.numPlayers, MAX_PLAYERS);
            exit(1);
        }
        else
        {
            for (int i = 0; i < game.numPlayers; i++)
            {
                sprintf(game.playerName[i], "Player %d", i + 1);
            }
        }

        if (game.gameBoard.numWinSymbols < 4 || game.gameBoard.numWinSymbols > MAX_WIN_SYMBOLS)
        {
            printf("Invalid number of symbols to win: %u (must be between 4 and %d)\n", game.gameBoard.numWinSymbols, MAX_WIN_SYMBOLS);
            exit(1);
        }
    }
    else
    {

        printf("Welcome to the 'Connect 4 Game' game!\n");
        printf("This program was developed by Tommaso Bocchietti back in 2017 at high school and updated in 2023.\n");

        print_horizontal_line(50, '-');

        for (int i = 0; i < game.numPlayers; i++)
        {
            printf("\nEnter the name of player %d: ", i + 1);
            scanf("%s", &game.playerName[i]);
            printf("Player %s is going to use: ", game.playerName[i]);
            PRINT_COLOURED(game.gameBoard.playerColors[i], "%c\n", game.gameBoard.playerSymbols[i]);
        }

        print_horizontal_line(50, '-');

        printf("\nTo choose who starts, let's roll a dice");
        for (int i = 0; i < 5; i++)
        {
            delay(200);
            printf(".");
        }

        srand(time(NULL));
        game.currentPlayerIndex = rand() % game.numPlayers;
        printf("\n%s starts! (press any key to continue)", game.playerName[game.currentPlayerIndex]);

        clear_input_buffer();
        getchar();
    }

    for (int r = 0; r < game.gameBoard.numRows; r++)
        for (int c = 0; c < game.gameBoard.numCols; c++)
            game.gameBoard.cells[r][c] = EMPTY_CELL;

    return game;
}
#include <stdio.h>
#include <stdlib.h>

#include "libs/cGETOPT/getopt.h"

#include "cmd.h"
#include "../definitions.h"

void C4G_Setup_CMD(game_t *game, int argc, char *argv[])
{
    int c;
    int option_index = 0;
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"board", required_argument, 0, 'b'},
        {"player", required_argument, 0, 'p'},
        {"winning", required_argument, 0, 'w'},
        {0, 0, 0, 0}};

    while ((c = getopt_long(argc, argv, "hb:p:w:", long_options, &option_index)) != -1)
    {
        switch (c)
        {
        case 'h':
            C4G_Setup_CMD_Help(argv[0]);
            break;

        case 'b':
            C4G_Setup_CMD_Board(game, optarg);
            break;

        case 'p':
            C4G_Setup_CMD_Player(game, optarg);
            break;

        case 'w':
            C4G_Setup_CMD_Winning_Symbols(game, optarg);
            break;

        default:
            printf("Unknown argument: %c %s\n", c, optarg);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < game->numPlayers; i++)
    {
        sprintf(game->playerName[i], "Player %d", i + 1);
    }
}

void C4G_Setup_CMD_Help(char *name)
{
    printf("Usage: %s [options]\n", name);
    printf("Options:\n"
           "-h, --help \t Show this help message and exit.\n"
           "-b, --board \t Set the board size in the format 'rows x columns'. Default: 6x7.\n"
           "-p, --player \t Set the number of players. Default: 2.\n"
           "-w, --winning \t Set the number of symbols to win. Default: 4.\n");

    exit(EXIT_SUCCESS);
}

void C4G_Setup_CMD_Board(game_t *game, char *arg)
{
    if (sscanf(arg, "%ux%u", &game->gameBoard->numRows, &game->gameBoard->numCols) != 2)
    {
        printf("Invalid board size: %s\n", arg);
        exit(EXIT_FAILURE);
    }

    if (game->gameBoard->numRows < 4 || game->gameBoard->numRows > MAX_ROWS)
    {
        printf("Invalid number of row: %u (must be between 4 and %d)\n", game->gameBoard->numRows, MAX_ROWS);
        exit(EXIT_FAILURE);
    }

    if (game->gameBoard->numCols < 4 || game->gameBoard->numCols > MAX_COLUMNS)
    {
        printf("Invalid number of column: %u (must be between 4 and %d)\n", game->gameBoard->numCols, MAX_COLUMNS);
        exit(EXIT_FAILURE);
    }
}

void C4G_Setup_CMD_Player(game_t *game, char *arg)
{
    if (sscanf(arg, "%u", &game->numPlayers) != 1)
    {
        printf("Invalid number of player: %s\n", arg);
        exit(EXIT_FAILURE);
    }

    if (game->numPlayers < 2 || game->numPlayers > MAX_PLAYERS)
    {
        printf("Invalid number of player: %u (must be between 2 and %d)\n", game->numPlayers, MAX_PLAYERS);
        exit(EXIT_FAILURE);
    }
}

void C4G_Setup_CMD_Winning_Symbols(game_t *game, char *arg)
{
    if (sscanf(arg, "%u", &game->gameBoard->numWinSymbols) != 1)
    {
        printf("Invalid number of symbols to win: %s\n", arg);
        exit(EXIT_FAILURE);
    }

    if (game->gameBoard->numWinSymbols < 4 || game->gameBoard->numWinSymbols > MAX_WIN_SYMBOLS)
    {
        printf("Invalid number of symbols to win: %u (must be between 4 and %d)\n", game->gameBoard->numWinSymbols, MAX_WIN_SYMBOLS);
        exit(EXIT_FAILURE);
    }
}
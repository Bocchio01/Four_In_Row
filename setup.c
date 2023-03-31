/*

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

struct game setupGame(int argc, char *argv[])
{
    struct game game;

    // Default values
    game.n_player = 2;
    game.player_index = 0;
    game.current_move.row = -1;
    game.current_move.col = -1;

    game.board.n_row = 6;
    game.board.n_col = 7;
    game.board.n_win_symbol = 4;
    for (int i = 0,
             symbols[] = {'x', 'o', '*', '@', '#', '$'},
             colors[] = {31, 33, 32, 34, 35, 36};
         i < MAX_N_PLAYER; i++)
    {
        game.board.symbols[i] = symbols[i]; // ASCII codes
        game.board.colors[i] = colors[i];   // ANSI color codes
    }

    // Parse command line arguments

    int c;
    int option_index = 0;
    static struct option long_options[] =
        {
            {"help", no_argument, 0, 'h'},
            {"board", required_argument, 0, 'b'},
            {"player", required_argument, 0, 'p'},
            {0, 0, 0, 0}};

    if (argc > 1)
    {
        while ((c = getopt_long(argc, argv, "hb:p:", long_options, &option_index)) != -1)
        {
            switch (c)
            {
            case 'h':
                printf("Help message for the game!\n");
                exit(0);
            case 'b':
                if (sscanf(optarg, "%ux%u", &game.board.n_row, &game.board.n_col) != 2)
                {
                    printf("Invalid board size: %s\n", optarg);
                    exit(1);
                }
                break;

            case 'p':
                if (sscanf(optarg, "%u", &game.n_player) != 1)
                {
                    printf("Invalid number of player: %s\n", optarg);
                    exit(1);
                }
                break;

            default:
                printf("Unknown argument: %c %s\n", c, optarg);
                exit(1);
            }
        }

        if (game.board.n_row < 4 || game.board.n_row > MAX_N_ROW)
        {
            printf("Invalid number of row: %u (must be between 4 and %d)\n", game.board.n_row, MAX_N_ROW);
            exit(1);
        }
        else if (game.board.n_col < 4 || game.board.n_col > MAX_N_COL)
        {
            printf("Invalid number of column: %u (must be between 4 and %d)\n", game.board.n_col, MAX_N_COL);
            exit(1);
        }

        if (game.n_player < 2 || game.n_player > MAX_N_PLAYER)
        {
            printf("Invalid number of player: %u (must be between 2 and %d)\n", game.n_player, MAX_N_PLAYER);
            exit(1);
        }
        else
        {
            for (int i = 0; i < game.n_player; i++)
            {
                sprintf(game.player_name[i], "Player %d", i + 1);
            }
        }
    }
    else
    {

        printf("Welcome to the 'Connect 4 Game' game!\n");
        printf("This program was developed by Tommaso Bocchietti back in 2017 at high school and updated in 2023.\n");

        print_horizontal_line(50, '-');

        for (int i = 0; i < game.n_player; i++)
        {
            printf("\nEnter the name of player %d: ", i + 1);
            scanf("%s", &game.player_name[i]);
            printf("Player %s is going to use: ", game.player_name[i]);
            PRINT_COLOURED(game.board.colors[i], "%c\n", game.board.symbols[i]);
        }

        print_horizontal_line(50, '-');

        printf("\nTo choose who starts, let's roll a dice");
        for (int i = 0; i < 5; i++)
        {
            delay(200);
            printf(".");
        }

        srand(time(NULL));
        game.player_index = rand() % game.n_player;
        printf("\n%s starts! (press any key to continue)", game.player_name[game.player_index]);

        clear_input_buffer();
        getchar();
    }

    for (int r = 0; r < game.board.n_row; r++)
        for (int c = 0; c < game.board.n_col; c++)
            game.board.board[r][c] = EMPTY_CELL;

    return game;
}
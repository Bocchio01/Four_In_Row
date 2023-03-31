/*
 * A (not to basic) 'Connect 4 Game' game implementation.
 *
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-03-30
 *
 * This program let two players play the game of 'Connect 4 Game' on the same computer.
 * The game is played on a 6x7 board, and the first player to get four of his/her symbols in a row (horizontally, vertically or diagonally) wins.
 * The players take turns inserting their symbols into the board, and the game ends when one of the players wins, or when the board is full.
 * No graphics are provided, this is just a console application.
 *
 * License: MIT
 *
 */

#include "utils.h"
#include "board.h"
#include "constant.h"
#include "setup.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{

	struct game game = setupGame(argc, argv);

	// Game loop
	while (true)
	{

		game.current_move.row = -1;
		game.current_move.col = -1;
		draw_board(game.board);

		while (game.current_move.row == -1)
		{
			printf("\n%s (", game.player_name[game.player_index]);
			PRINT_COLOURED(game.board.colors[game.player_index], "%c", game.board.symbols[game.player_index]);
			printf(") selects any column from 1 to 7: ");
			while (scanf("%d", &game.current_move.col) != 1)
			{
				printf("You can enter only integer values: ");
				scanf("%*s");
			}
			game.current_move.col--; // Because of the array index from 0 to 6

			game.current_move.row = insert_into_board(&game.board, game.player_index, game.current_move.col);
		};

		if (check_winner(game.board, game.current_move))
		{
			draw_board(game.board);
			printf("\nCongratulations %s, you won! :)", game.player_name[game.player_index]);
			break;
		}

		if (check_tie(game.board))
		{
			draw_board(game.board);
			printf("\nOhoh, looks like the game ended in draw...");
			break;
		}

		game.player_index = (game.player_index + 1) % game.n_player;
	};

	printf("\n\n");
	system("PAUSE");
	return 0;
}

/*
 * A (not so basic) 'Connect 4 Game' implementation.
 *
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-03-30
 *
 * This program let two players play the 'Connect 4 Game' on the same computer.
 * The game is played on a 6x7 board, and the first player to get four of his/her symbols in a row (horizontally, vertically or diagonally) wins.
 * The players take turns inserting their symbols into the board, and the game ends when one of the players wins, or when the board is full.
 * No graphics are provided, this is just a console application.
 * It is possible to play personalized versions of the game by passing parameters to the program.
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

	struct Game game = setupGame(argc, argv);

	// Game loop
	while (true)
	{

		game.currentMove.row = -1;
		game.currentMove.column = -1;
		draw_board(game.gameBoard);

		while (game.currentMove.row == -1)
		{
			printf("\n%s (", game.playerName[game.currentPlayerIndex]);
			PRINT_COLOURED(game.gameBoard.playerColors[game.currentPlayerIndex], "%c", game.gameBoard.playerSymbols[game.currentPlayerIndex]);
			printf(") selects any column from 1 to 7: ");
			while (scanf("%d", &game.currentMove.column) != 1)
			{
				printf("You can enter only integer values: ");
				scanf("%*s");
			}
			game.currentMove.column--; // Because of the array index from 0 to 6

			game.currentMove.row = insert_into_board(&game.gameBoard, game.currentPlayerIndex, game.currentMove.column);
		};

		if (check_winner(game.gameBoard, game.currentMove))
		{
			draw_board(game.gameBoard);
			printf("\nCongratulations %s, you won! :)", game.playerName[game.currentPlayerIndex]);
			break;
		}

		if (check_tie(game.gameBoard))
		{
			draw_board(game.gameBoard);
			printf("\nOhoh, looks like the game ended in draw...");
			break;
		}

		game.currentPlayerIndex = (game.currentPlayerIndex + 1) % game.numPlayers;
	};

	printf("\n\n");
	system("PAUSE");
	return 0;
}

/*
 * A simple 'Four in a Row' game implementation.
 *
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-03-30
 *
 * This program let two players play the game of 'Four in a Row' on the same computer.
 * The game is played on a 6x7 board, and the first player to get four of his/her symbols in a row (horizontally, vertically or diagonally) wins.
 * The players take turns inserting their symbols into the board, and the game ends when one of the players wins, or when the board is full.
 * No graphics are provided, this is just a console application.
 *
 * License: MIT
 *
 */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 13
#define COLUMNS 25
#define WINNING_SYMBOLS 4
#define PLAYER_NUMBER 2

#define EMPTY_CELL_VALUE -1 // The value of an empty cell in the board. Must be a negative number!
#define EMPTY_CELL_SYMBOL 46

#define PRINT_COLOURED(c, f, s) printf("\033[%dm" f "\033[0m", c, s)

struct players
{
	char name[20];
	int symbol;
	int color;
};

void draw_board(int board[ROWS][COLUMNS], struct players players[PLAYER_NUMBER])
{
	system("@cls || clear");

	for (int r = ROWS - 1; r >= 0; r--)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			if (board[r][c] >= 0)
				PRINT_COLOURED(players[board[r][c]].color, " %c ", players[board[r][c]].symbol);
			else
				printf(" %c ", EMPTY_CELL_SYMBOL);
		}
		printf("\n");
	}

	for (int i = 0; i < COLUMNS; i++)
		printf("---");
	printf("\n");

	for (int i = 0; i < COLUMNS; i++)
		i + 1 > 9 ? printf(" %d", i + 1) : printf(" %d ", i + 1);
	printf("\n");
}

bool is_insert_valid(int board[ROWS][COLUMNS], int selected_column)
{
	if ((selected_column < 0) || (selected_column > COLUMNS - 1))
	{
		printf("\nColumn's index out of range");
		return false;
	}

	if (board[ROWS - 1][selected_column] != -1)
	{
		printf("\nThe selected column is full");
		return false;
	}

	return true;
}

int insert_into_board(int (*board)[ROWS][COLUMNS], int symbol, int selected_column)
{

	if (!is_insert_valid(*board, selected_column))
		return -1;

	int r = 0;
	while ((*board)[r][selected_column] != EMPTY_CELL_VALUE)
		r++;
	(*board)[r][selected_column] = symbol;

	return r;
}

bool check_winner(int board[ROWS][COLUMNS], int position_array[2])
{

	int symbol = board[position_array[0]][position_array[1]];

	for (int i = 0; i <= 3; i++)
	{
		int count = 0;

		for (int dir = EMPTY_CELL_VALUE; dir <= 1; dir += 2)
		{
			int r = position_array[0];
			int c = position_array[1];

			while ((r >= 0) && (r < ROWS) && (c >= 0) && (c < COLUMNS) && (board[r][c] == symbol))
			{
				count++;
				r += dir * (i / 3 - 1);
				c += dir * (i % 3 - 1);
			}
		}

		if (--count >= WINNING_SYMBOLS) // Because the central symbol is counted twice
			return true;
	}

	return false;
}

bool check_tie(int board[ROWS][COLUMNS])
{
	for (int c = 0; c < COLUMNS; c++)
		if (board[ROWS - 1][c] == EMPTY_CELL_VALUE)
			return false;

	return true;
}

int main(int argc, char *argv[])
{

	// Variables declaration
	bool debug = argc > 1;

	int board[ROWS][COLUMNS], player_index;
	struct players players[PLAYER_NUMBER];

	int symbol_array[] = {'x', 'o', '*', '@', '#', '$'}; // ASCII codes
	int color_array[] = {31, 33, 32, 34, 35, 36};		 // ANSI color codes

	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			board[r][c] = EMPTY_CELL_VALUE;

	// Program begin
	if (!debug)
	{
		printf("Welcome to the 'Four in a Row' game!\n");
		printf("This program was developed by Tommaso Bocchietti back in 2017 at high school and updated in 2023.\n");

		print_horizontal_line(50, '-');

		for (int i = 0; i < PLAYER_NUMBER; i++)
		{
			printf("\nEnter the name of player %d: ", i + 1);
			scanf("%s", players[i].name);
			players[i].symbol = symbol_array[i];
			players[i].color = color_array[i];
			printf("Player %s is going to use: ", players[i].name);
			PRINT_COLOURED(players[i].color, "%c\n", players[i].symbol);
		}

		print_horizontal_line(50, '-');

		printf("\nTo choose who starts, let's roll a dice");
		for (int i = 0; i < 5; i++)
		{
			delay(200);
			printf(".");
		}

		srand(time(NULL));
		player_index = rand() % PLAYER_NUMBER;
		printf("\n%s starts! (press any key to continue)", players[player_index].name);

		clear_input_buffer();
		getchar();
	}
	else
	{
		for (int i = 0; i < PLAYER_NUMBER; i++)
		{
			sprintf(players[i].name, "Player %d", i + 1);
			players[i].symbol = symbol_array[i];
			players[i].color = color_array[i];
		}

		player_index = 0;
	}

	// Game loop
	while (true)
	{

		draw_board(board, players);
		int selected_column = -1;
		int inserted_row = -1;

		while (inserted_row == -1)
		{
			printf("\n%s (", players[player_index].name);
			PRINT_COLOURED(players[player_index].color, "%c", players[player_index].symbol);
			printf(") selects any column from 1 to 7: ");
			while (scanf("%d", &selected_column) != 1)
			{
				printf("You can enter only integer values: ");
				scanf("%*s");
			}
			selected_column--; // Because of the array index from 0 to 6

			inserted_row = insert_into_board(&board, player_index, selected_column);
		};

		int position_array[2] = {inserted_row, selected_column};
		if (check_winner(board, position_array))
		{
			draw_board(board, players);
			printf("\nCongratulations %s, you won! :)", players[player_index].name);
			break;
		}

		if (check_tie(board))
		{
			draw_board(board, players);
			printf("\nOhoh, looks like the game ended in draw...");
			break;
		}

		player_index = (player_index + 1) % PLAYER_NUMBER;
	};

	printf("\n\n");
	system("PAUSE");
	return 0;
}

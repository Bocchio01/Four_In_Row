/*
 * A simple 'Four in a Row' game implementation.
 *
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-03-29
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

#define ROWS 6
#define COLUMNS 7
#define PLAYER_NUMBER 2

void draw_board(int board[ROWS][COLUMNS])
{
	system("cls");

	for (int r = ROWS - 1; r >= 0; r--)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			printf(" %c ", board[r][c]);
		}
		printf("\n");
	}
	printf(" -------------------");
	printf("\n 1  2  3  4  5  6  7\n");
}

bool is_insert_valid(int board[ROWS][COLUMNS], int selected_column)
{
	if ((selected_column < 0) || (selected_column > COLUMNS - 1))
	{
		printf("\nColumn's index out of range");
		return false;
	}

	if (board[ROWS - 1][selected_column] != 46)
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
	while ((*board)[r][selected_column] != 46)
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

		for (int dir = -1; dir <= 1; dir += 2)
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

		if (--count >= 4) // Because the central symbol is counted twice
			return true;
	}

	return false;
}

bool check_tie(int board[ROWS][COLUMNS])
{
	for (int c = 0; c < COLUMNS; c++)
		if (board[ROWS - 1][c] == 46)
			return false;

	return true;
}

int main(int argc, char *argv[])
{

	// Variables declaration
	bool debug = argc > 1;

	int board[ROWS][COLUMNS], player_index;

	struct players
	{
		char name[20];
		int symbol;
	} players[PLAYER_NUMBER];

	enum symbol
	{
		CROSS = 120,
		CIRCLE = 111
	};

	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			board[r][c] = 46;

	players[0].symbol = CROSS;
	players[1].symbol = CIRCLE;

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
			printf("Player %s is going to use: %c\n", players[i].name, players[i].symbol);
		}

		print_horizontal_line(50, '-');

		printf("\nTo choose who starts, let's roll a dice");
		for (int i = 0; i < 5; i++)
		{
			delay(200);
			printf(".");
		}

		srand(time(NULL));
		player_index = rand() % 2;
		printf("\n%s starts! (press any key to continue)", players[player_index].name);

		clear_input_buffer();
		getchar();
	}
	else
	{
		strcpy(players[0].name, "Player 1");
		strcpy(players[1].name, "Player 2");
		player_index = 0;
	}

	// Game loop
	do
	{

		draw_board(board);
		int selected_column = -1;
		int inserted_row = -1;

		do
		{
			printf("\n%s (%c) selects any column from 1 to 7: ", players[player_index].name, players[player_index].symbol);
			while (scanf("%d", &selected_column) != 1)
			{
				printf("You can enter only integer values: ");
				scanf("%*s");
			}
			selected_column--; // Because of the array index from 0 to 6

			inserted_row = insert_into_board(&board, players[player_index].symbol, selected_column);
		} while (inserted_row == -1);

		int position_array[2] = {inserted_row, selected_column};
		if (check_winner(board, position_array))
		{
			draw_board(board);
			printf("\nCongratulations %s, you won! :)", players[player_index].name);
			break;
		}

		if (check_tie(board))
		{
			draw_board(board);
			printf("\nOhoh, looks like the game ended in draw...");
			break;
		}

		player_index = (player_index + 1) % 2;

	} while (true);

	printf("\n\n");
	system("PAUSE");
	return 0;
}

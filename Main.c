#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 6
#define COLUMNS 7
#define PLAYER_NUMBER 2

void print_board(int board_game[ROWS][COLUMNS])
{
	system("cls");

	for (int r = ROWS - 1; r >= 0; r--)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			printf(" %c ", board_game[r][c]);
		}
		printf("\n");
	}
	printf(" -------------------");
	printf("\n 1  2  3  4  5  6  7\n");
}

bool is_insert_valid(int board_game[ROWS][COLUMNS], int selected_column)
{
	if ((selected_column < 0) || (selected_column > COLUMNS - 1))
	{
		printf("\nNumero colonna non valido");
		return false;
	}

	if (board_game[ROWS - 1][selected_column] != 46)
	{
		printf("\nLa colonna selezionata e' gia' piena");
		return false;
	}

	return true;
}

int insert_symbol(int (*board_game)[ROWS][COLUMNS], int symbol, int selected_column)
{

	if (!is_insert_valid(*board_game, selected_column))
		return -1;

	int r = 0;
	while ((*board_game)[r][selected_column] != 46)
		r++;
	(*board_game)[r][selected_column] = symbol;

	return r;
}

bool check_winner(int board_game[ROWS][COLUMNS], int position_array[2])
{

	int symbol = board_game[position_array[0]][position_array[1]];

	for (int i = 0; i < 9; i++)
	{
		if (i != 4)
		{
			int count = 0;
			int r = position_array[0];
			int c = position_array[1];
			while ((r >= 0) && (r < ROWS) && (c >= 0) && (c < COLUMNS) && (board_game[r][c] == symbol))
			{
				count++;
				r += i / 3 - 1;
				c += i % 3 - 1;
			}
			if (count >= 4)
				return true;
		}
	}

	return false;
}

bool check_parity(int board_game[ROWS][COLUMNS])
{
	for (int c = 0; c < COLUMNS; c++)
		if (board_game[ROWS - 1][c] == 46)
			return false;

	return true;
}

int main()
{

	// Dichiarazione variabili
	int board_game[ROWS][COLUMNS], player_index;

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
			board_game[r][c] = 46;

	players[0].symbol = CROSS;
	players[1].symbol = CIRCLE;

	// Inizio programma
	printf("Ecco un programma per giocare al gioco: 'Forza 4'\n\n\n");

	for (int i = 0; i < PLAYER_NUMBER; i++)
	{
		printf("Inserisci il nome del giocatore %d: ", i + 1);
		scanf("%s", players[i].name);
		printf("Il giocatore %s utilizzera': %c\n\n", players[i].name, players[i].symbol);
	}

	printf("\nPer scegliere chi inizia tiriamo un dado");
	for (int i = 0; i < 5; i++)
	{
		delay(200);
		printf(".");
	}

	srand(time(NULL));
	player_index = rand() % 2;
	printf("\nInizia %s! (premi un tasto per continuare)", players[player_index].name);

	clear_input_buffer();
	getchar();

	// Inizio gioco
	do
	{

		print_board(board_game);
		int selected_column = -1;
		int inserted_row = -1;

		do
		{
			printf("\n%s (%c) seleziona una colonna da 1 a 7: ", players[player_index].name, players[player_index].symbol);
			while (scanf("%d", &selected_column) != 1)
			{
				printf("Puoi inserire solo valori numerici: ");
				scanf("%*s");
			}
			selected_column--; // Because of the array index from 0 to 6

			inserted_row = insert_symbol(&board_game, players[player_index].symbol, selected_column);
		} while (inserted_row == -1);

		int position_array[2] = {inserted_row, selected_column};
		if (check_winner(board_game, position_array))
		{
			print_board(board_game);
			printf("\nComplimenti %s, hai vinto", players[player_index].name);
			break;
		}

		if (check_parity(board_game))
		{
			print_board(board_game);
			printf("\nOhoh, sembra che il gioco sia finito in pareggio...");
			break;
		}

		player_index = (player_index + 1) % 2;

	} while (true);

	printf("\n\n");
	// system("PAUSE");
	return 0;
}

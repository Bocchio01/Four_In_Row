/*
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-04-01
 *
 * This file is part of the 'Connect 4 Game' project.
 * It contains the main function of the game, such as:
 * - Draw the board
 * - Insert a symbol into the board
 * - Check for wins or ties
 *
 * License: MIT
 *
 */

#include "utils.h"
#include "board.h"
#include "constant.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void draw_board(struct Board board)
{
    system("@cls || clear");

    for (int r = board.numRows - 1; r >= 0; r--)
    {
        for (int c = 0; c < board.numCols; c++)
        {
            if (board.cells[r][c] >= 0)
                PRINT_COLOURED(board.playerColors[board.cells[r][c]], " %c ", board.playerSymbols[board.cells[r][c]]);
            else
                printf(" . ");
        }
        printf("\n");
    }

    for (int i = 0; i < board.numCols; i++)
        printf("---");
    printf("\n");

    for (int i = 0; i < board.numCols; i++)
        i + 1 > 9 ? printf(" %d", i + 1) : printf(" %d ", i + 1);
    printf("\n");
}

bool is_insert_valid(struct Board board, int selected_column)
{
    if ((selected_column < 0) || (selected_column > board.numCols - 1))
    {
        printf("\nColumn's index out of range");
        return false;
    }

    if (board.cells[board.numRows - 1][selected_column] != EMPTY_CELL)
    {
        printf("\nThe selected column is full");
        return false;
    }

    return true;
}

int insert_into_board(struct Board *board, int symbol, int selected_column)
{

    if (!is_insert_valid(*board, selected_column))
        return -1;

    int r = 0;
    while (board->cells[r][selected_column] != EMPTY_CELL)
        r++;
    board->cells[r][selected_column] = symbol;

    return r;
}

bool check_winner(struct Board board, struct BoardCoordinates current_move)
{

    int symbol = board.cells[current_move.row][current_move.column];

    for (int i = 0; i <= 3; i++)
    {
        int count = 0;

        for (int dir = -1; dir <= 1; dir += 2)
        {
            int r = current_move.row;
            int c = current_move.column;

            while ((r >= 0) && (r < board.numRows) && (c >= 0) && (c < board.numCols) && (board.cells[r][c] == symbol))
            {
                count++;
                r += dir * (i / 3 - 1);
                c += dir * (i % 3 - 1);
            }
        }

        if (--count >= board.numWinSymbols) // Because the central symbol is counted twice
            return true;
    }

    return false;
}

bool check_tie(struct Board board)
{
    for (int c = 0; c < board.numCols; c++)
        if (board.cells[board.numRows - 1][c] == EMPTY_CELL)
            return false;

    return true;
}
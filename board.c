/*
 * A simple 'Connect 4 Game' game implementation.
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
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void draw_board(struct board board)
{
    system("@cls || clear");

    for (int r = board.n_row - 1; r >= 0; r--)
    {
        for (int c = 0; c < board.n_col; c++)
        {
            if (board.board[r][c] >= 0)
                PRINT_COLOURED(board.colors[board.board[r][c]], " %c ", board.symbols[board.board[r][c]]);
            else
                printf(" . ");
        }
        printf("\n");
    }

    for (int i = 0; i < board.n_col; i++)
        printf("---");
    printf("\n");

    for (int i = 0; i < board.n_col; i++)
        i + 1 > 9 ? printf(" %d", i + 1) : printf(" %d ", i + 1);
    printf("\n");
}

bool is_insert_valid(struct board board, int selected_column)
{
    if ((selected_column < 0) || (selected_column > board.n_col - 1))
    {
        printf("\nColumn's index out of range");
        return false;
    }

    if (board.board[board.n_row - 1][selected_column] != EMPTY_CELL)
    {
        printf("\nThe selected column is full");
        return false;
    }

    return true;
}

int insert_into_board(struct board *board, int symbol, int selected_column)
{

    if (!is_insert_valid(*board, selected_column))
        return -1;

    int r = 0;
    while (board->board[r][selected_column] != EMPTY_CELL)
        r++;
    board->board[r][selected_column] = symbol;

    return r;
}

bool check_winner(struct board board, struct current_move current_move)
{

    int symbol = board.board[current_move.row][current_move.col];

    for (int i = 0; i <= 3; i++)
    {
        int count = 0;

        for (int dir = -1; dir <= 1; dir += 2)
        {
            int r = current_move.row;
            int c = current_move.col;

            while ((r >= 0) && (r < board.n_row) && (c >= 0) && (c < board.n_col) && (board.board[r][c] == symbol))
            {
                count++;
                r += dir * (i / 3 - 1);
                c += dir * (i % 3 - 1);
            }
        }

        if (--count >= board.n_win_symbol) // Because the central symbol is counted twice
            return true;
    }

    return false;
}

bool check_tie(struct board board)
{
    for (int c = 0; c < board.n_col; c++)
        if (board.board[board.n_row][c] == EMPTY_CELL)
            return false;

    return true;
}
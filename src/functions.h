/*
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-04-01
 *
 * This file is part of the 'Connect 4 Game' project.
 *
 * License: MIT
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "definitions.h"

void draw_board(board_t *board);

bool is_insert_valid(board_t *board, int selected_column);

int insert_into_board(board_t *board, int symbol, int selected_column);

bool check_winner(board_t *board, board_index_t *current_move);

bool check_tie(board_t *board);

#endif
/*
 * A simple 'Connect 4 Game' game implementation.
 *
 * Author: Tommaso Bocchietti
 * Email: tommaso.bocchietti@gmail.com
 * Date: 2023-03-29
 *
 * Utils functions used into the main program.
 *
 * License: MIT
 *
 */

#include "constant.h"
#include <stdbool.h>

#ifndef BOARD_H
#define BOARD_H

void draw_board(struct board board);

bool is_insert_valid(struct board board, int selected_column);

int insert_into_board(struct board *board, int symbol, int selected_column);

bool check_winner(struct board board, struct current_move current_move);

bool check_tie(struct board board);

#endif
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

#include "constant.h"
#include <stdbool.h>

#ifndef BOARD_H
#define BOARD_H

void draw_board(struct Board board);

bool is_insert_valid(struct Board board, int selected_column);

int insert_into_board(struct Board *board, int symbol, int selected_column);

bool check_winner(struct Board board, struct BoardCoordinates current_move);

bool check_tie(struct Board board);

#endif
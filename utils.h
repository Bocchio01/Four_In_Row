/*
 * A simple 'Four in a Row' game implementation.
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

#ifndef UTILS_H
#define UTILS_H

void delay(int milliseconds);

void clear_input_buffer();

void print_horizontal_line(int width, char symbol);

#endif
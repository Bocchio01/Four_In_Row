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

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds)
{
    time_t start_time = time(NULL);
    while ((time(NULL) - start_time) * 1000 < milliseconds)
        ;
}

void clear_input_buffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void print_horizontal_line(int width, char symbol)
{
    printf("\n");
    for (int i = 0; i < width; i++)
    {
        printf("%c", symbol);
    }
    printf("\n");
}
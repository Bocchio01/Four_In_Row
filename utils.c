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
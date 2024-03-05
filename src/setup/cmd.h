#ifndef CMD_H
#define CMD_H

#include "../definitions.h"

void C4G_Setup_CMD(game_t *game, int argc, char *argv[]);

void C4G_Setup_CMD_Help(char *name);

void C4G_Setup_CMD_Board(game_t *game, char *arg);

void C4G_Setup_CMD_Player(game_t *game, char *arg);

void C4G_Setup_CMD_Winning_Symbols(game_t *game, char *arg);

#endif
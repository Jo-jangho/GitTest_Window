#include "main.h"

#ifndef __DRAW_PROC_H__
#define __DRAW_PROC_H__

/* enum */
enum { state_ready, state_play };

/* var */
int gamestate = state_ready;

/* function */
void DrawStage();
void drawchar(Creature *cr);

#endif
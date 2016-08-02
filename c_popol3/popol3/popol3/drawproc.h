#include "main.h"

#ifndef __DRAW_PROC_H__
#define __DRAW_PROC_H__

/* enum */
extern enum{ state_ready, state_play };

/* var */
extern int gamestate;
extern long readycount;

/* function */
void DrawStage();
void drawchar(Creature *cr);
void draw_number();
void map_box();
void t_design();
void Ending();
void Tuto();
void m_design();
void Ball();

#endif
#ifndef __LOGIC_PROC_H__
#define __LOGIC_PROC_H__

/* enum */
enum{ state_ready, state_play };

/* var */
int gamestate = state_ready;
long readysec = 0;
long readycount = 4;

/* function */
void ready_go();
void initEnemy();
void moveEnemy();
void SetPlayerSize();
void SetEnemy(Creature* pObj);

#endif
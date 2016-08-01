#ifndef _MAIN_H_
#define _MAIN_H_

/* menu define */
#define TITLE		1
#define MENU		2
#define GAME		3
#define STAGECLEAR	4
#define STAGEOVER	5

/* size */
#define D_SIZE		10
#define WIDTH		80
#define HEIGHT		40

/* key value define */
#define LEFTKEY		75
#define RIGHTKEY	77

/* color define */
#define DARKNESS_BLUE			1
#define DARKNESS_GREEN			2
#define DARKNESS_BLUISH_GREEN	3
#define DARKNESS_RED			4
#define DARKNESS_PINK			5
#define DARKNESS_REDCLAY		6
#define IVORY					7
#define GRAY					8
#define BLUE					9
#define GREEN					10
#define BLUISH_GREEN			11
#define RED						12
#define PINK					13
#define YELLOW					14
#define WHITE					15

/* var */
int sceneState;
int score;
int hi_score;
long scoreSec;

/* time var*/
long sec, milsec;
long curTime, oldTime;
long elapsedTime;
long testTime;

/* Creature*/
typedef struct S_Creature
{
	char m_shape[8];	
	int m_color;
	int m_posx;
	int m_posy;
	int m_isAlive;
}Creature;

/* Creature define */
Creature circle[D_SIZE];
Creature player;

/* function */
void KeyProcess(int scene);
void LogicProcess(int scene);
void DrawProcess(int scene);
void InitData();
void Init_val();
void init_creature(Creature *cr, char* str, int posx, int posy);
void save_data();
void load_data();

#endif
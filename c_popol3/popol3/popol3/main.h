#ifndef _MAIN_H_
#define _MAIN_H_

/* menu define */
#define TITLE		1
#define MENU		2
#define TUTORIAL	3
#define GAME		4
#define STAGEOVER	5

/* size */
#define D_SIZE		10
#define WIDTH		40
#define HEIGHT		25

/* key value define */
#define SPACEBAR	32
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

/* etc */
#define MAX_TIME	20
#define LEFT		1
#define RIGHT		2

/* var */
int sceneState;
int hi_score;

/* time var*/
long sec, milsec;
long curTime, oldTime;
long elapsedTime;

/* Creature*/
typedef struct S_Creature
{
	char m_shape[12];	// 모양
	int m_color;		// 색
	int m_posx;			// x좌표
	int m_posy;			// y좌표
	int m_isAlive;		// 생존 여부
	int m_size;			// 가로 길이
	int m_score;		// 점수

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
void init_creature(Creature *cr, char* str, int posx, int posy, int color, int size);
void save_data();
void load_data();
void SetScore(Creature *pObj, int color);

#endif
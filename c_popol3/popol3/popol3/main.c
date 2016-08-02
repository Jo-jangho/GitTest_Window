// 게임제작의 기능..
// 반복문이 기본적으로동작...
// 반복문 내부 3요소.
// 키입력, 로직구현, 화면에 출력
#include <stdio.h>
#include <time.h>

#include "main.h"
#include "grpengine.h"

int main(void)
{
	sceneState = TITLE;
	InitData();

	while (1)
	{
		//화면을지움
		ClearScreen();

		/* time */
		curTime = clock();
		elapsedTime = curTime - oldTime;
		oldTime = curTime;

		// 로직처리
		KeyProcess(sceneState);
		LogicProcess(sceneState);
		DrawProcess(sceneState);
		Sleeped(100);
	}

	return 0;
}

void InitData()
{
	for (int i = 0; i < D_SIZE; i++)
	{
		init_creature(&circle[i], "●", 0, 0, BLUE, 1);
		circle[i].m_isAlive = 0;
	}
	/* init player */
	init_creature(&player, "===========", (WIDTH / 2) - 4, HEIGHT - 1, WHITE, 11);

	Init_val();
}

void Init_val()
{
	hi_score = 0;
	sec = 0;
	milsec = 0;
	curTime = oldTime = clock();
	load_data();
}

void init_creature(Creature *cr, char* str, int posx, int posy, int color, int size)
{
	cr->m_posx = posx;
	cr->m_posy = posy;
	cr->m_isAlive = 1;
	strcpy(cr->m_shape, str);
	cr->m_size = size;
	cr->m_color = color;

	SetScore(cr, color);
}

void SetScore(Creature *pObj, int color)
{
	switch (color)
	{
	case BLUE:
		pObj->m_score = 50;
		break;
	case RED:
		pObj->m_score = 100;
		break;
	case GREEN:
		pObj->m_score = 150;
		break;
	default:
		pObj->m_score = 0;
		break;
	}
}

void save_data()
{
	if (player.m_score <= hi_score)
	{
		return;
	}

	FILE *fp;
	fp = fopen("save.dat", "w");
	if (fp == NULL)
	{
		return;
	}

	hi_score = player.m_score;
	fwrite(&player.m_score, sizeof(int), 1, fp);

	fclose(fp);
}

void load_data()
{
	FILE *fp;
	fp = fopen("save.dat", "r");
	if (fp == NULL)
	{
		return;
	}
	fread(&hi_score, sizeof(int), 1, fp);

	fclose(fp);
}
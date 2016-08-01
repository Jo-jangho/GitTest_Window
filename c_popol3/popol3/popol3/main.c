// 게임제작의 기능..
// 반복문이 기본적으로동작...
// 반복문 내부 3요소.
// 키입력, 로직구현, 화면에 출력
#include <stdio.h>
#include "main.h"
#include "grpengine.h"

int main(void)
{
	InitData();

	while (1)
	{
		//화면을지움
		ClearScreen();

		// 로직처리
		KeyProcess(sceneState);
		LogicProcess(sceneState);
		DrawProcess(sceneState);
		Sleeped(80);
	}

	return 0;
}

void InitData()
{
	sceneState = TITLE;

	Init_val();

	for (int i = 0; i < D_SIZE; i++)
	{
		init_creature(&circle[i], "♨", 5, 21);
		circle[i].m_isAlive = 0;
	}

	init_creature(&player, "옷", 10, 24);

	curTime = oldTime = clock();
}

void Init_val()
{
	score = 0;
	hi_score = 0;
	sec = 0;
	milsec = 0;
}

void init_creature(Creature *cr, char* str, int posx, int posy)
{
	cr->m_posx = posx;
	cr->m_posy = posy;
	cr->m_isAlive = 1;
	strcpy(cr->m_shape, str);
}

void save_data()
{
	if (score <= hi_score)
	{
		return;
	}

	FILE *fp;
	fp = fopen("save.dat", "w");
	if (fp == NULL)
	{
		return;
	}

	hi_score = score;
	fwrite(&score, sizeof(int), 1, fp);

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

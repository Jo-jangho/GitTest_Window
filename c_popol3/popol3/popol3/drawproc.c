#include <stdio.h>
#include "grpengine.h"
#include "main.h"
#include "drawproc.h"

void DrawProcess(int scene)
{
	switch (scene)
	{
	case TITLE:
		SetColor(14);
		gotoxy(5, 5);
		printf("drawscene TITLE Test");
		break;
	case MENU:
		SetColor(14);
		gotoxy(5, 5);
		printf("drawscene MENU Test");
		break;
	case GAME:
		DrawStage();
		break;
	case STAGECLEAR:
		break;
	case STAGEOVER:
		break;
	}
}

void DrawStage()
{
	//���� - score, time, �ְ�����.
	gotoxy(1, 3);
	printf("score:%d", score);//���ھ�.... ���Ŀ� ���� ���� ���.
	gotoxy(30, 3);
	printf("time: %ld. %ld", sec, milsec);//�ð�.... ���Ŀ� ���� ���� ���.

	//�ٴ���
	for (int i = 0; i < (WIDTH / 2); i++)
	{
		gotoxy(i, 25);
		printf("-");
	}

	//�����̴� ��ü��---------------
	for (int i = 0; i < D_SIZE; i++)
	{
		if (circle[i].m_isAlive == 1)
			drawchar(&circle[i]);
	}
	//----------------------------------------
	drawchar(&player);
}

void drawchar(Creature *cr)
{
	gotoxy(cr->m_posx, cr->m_posy);
	printf("%s", cr->m_shape);
}

//void draw_number()
//{
//	if (gamestate == state_ready)
//	{
//		//�ʸ� ������ ���  (logic)
//		if (readycount > 0)
//		{
//			gotoxy(10, 5);
//			printf("Ready");
//			gotoxy(12, 6);
//			printf("%ld", readycount);
//		}
//		if (readycount <= 0)
//		{
//			gotoxy(10, 7);
//			printf("go!!!");
//		}
//	}
//}
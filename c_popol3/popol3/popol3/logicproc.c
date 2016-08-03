#include <stdio.h>
#include <time.h>

#include "main.h"
#include "logicproc.h"

void LogicProcess(int scene)
{
	switch (scene)
	{
	case TITLE:
		break;
	case MENU:
		break;
	case GAME:
		ready_go();

		if (gamestate == state_play)
		{
			//----- 시간계산-----------------
			milsec += elapsedTime;
			if (milsec >= 1000)
			{
				milsec = 0;
				sec++;
				if (sec >= MAX_TIME)
				{
					sceneState = STAGEOVER;
				}
			}
			//-------
			moveEnemy();
			for (int i = 0; i < D_SIZE; i++)
			{
				if (circle[i].m_posy >= player.m_posy - 1)
				{
					if (circle[i].m_posx >= player.m_posx && circle[i].m_posx <= (player.m_posx + player.m_size))
					{
						SetEnemy(&circle[i]);
						
						player.m_score += circle[i].m_score;
						SetPlayerSize();
					}
				}
			}
		}
		break;
	case TUTORIAL:
		break;
	case STAGEOVER:
		save_data();
		break;
	}
}

void SetPlayerSize()
{
	int score = player.m_score;
	if (player.m_score >= 300 && player.m_score < 800)
	{
		strcpy(player.m_shape, "=========");
		player.m_size = 9;
	}
	else if (player.m_score >= 800 && player.m_score < 1200)
	{
		strcpy(player.m_shape, "=======");
		player.m_size = 7;
	}
	else if (player.m_score >= 1200 && player.m_score < 1800)
	{
		strcpy(player.m_shape, "=====");
		player.m_size = 5;
	}
	else if (player.m_score >= 1800 && player.m_score < 2500)
	{
		strcpy(player.m_shape, "===");
		player.m_size = 3;
	}
	else if (player.m_score >= 2500)
	{
		strcpy(player.m_shape, "==");
		player.m_size = 2;
	}
}

void ready_go()
{
	if (gamestate == state_ready)
	{
		readysec += elapsedTime;
		if (readysec >= 1000) //1초가 넘을때마나
		{
			readycount--; //카운트값을 삭제하고
			readysec = 0; //프레임별 시간을 초기화
		}
	}

	if (readycount <= -1)
	{
		readysec = 0;
		readycount = 4;
		initEnemy();
		gamestate = state_play;
	}
}

void initEnemy()
{
	/* init circle */
	srand(time(NULL));
	for (int i = 0; i < D_SIZE; i++)
	{
		SetEnemy(&circle[i]);
	}
}

void SetEnemy(Creature* pObj)
{
	/* var */
	int rnd_color = 0;
	int rnd_x = 0;
	int rnd_y = 0;

	/* Set Color */
	rnd_color = rand() % 3;
	rnd_x = rand() % (WIDTH - 2) + 2;
	rnd_y = rand() % 20 - 20;

	switch (rnd_color)
	{
	case 0:
		rnd_color = BLUE;
		break;
	case 1:
		rnd_color = RED;
		break;
	case 2:
		rnd_color = GREEN;
		break;
	}

	pObj->m_posx = rnd_x;
	pObj->m_posy = rnd_y;
	pObj->m_color = rnd_color;
	pObj->m_isAlive = 0;

	SetScore(pObj, rnd_color);
}

void moveEnemy()
{
	for (int i = 0; i < D_SIZE; i++)
	{
		circle[i].m_posy++;
		if (circle[i].m_posy >= 4)
		{
			circle[i].m_isAlive = 1;
		}
		if (circle[i].m_posy >= HEIGHT && circle[i].m_isAlive == 1)
		{
			SetEnemy(&circle[i]);
		}
	}
}
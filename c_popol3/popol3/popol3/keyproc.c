#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "main.h"
#include "drawproc.h"

void KeyProcess(int scene)
{
	char ch = 0;;
	while (kbhit())
	{
		ch = getch();
	}

	switch (scene)
	{
	case TITLE:
		if (ch == SPACEBAR)
		{
			sceneState = MENU;
		}
		if (ch == 'q')
		{
			exit(1);
		}
		break;
	case MENU:
		if (ch == SPACEBAR)
		{
			sceneState = GAME;
			gamestate = state_ready;
			InitData();
		}
		if (ch == 't')
		{
			sceneState = TUTORIAL;
		}
		if (ch == 'q')
		{
			exit(1);
		}
		break;
	case TUTORIAL:
		break;
	case GAME:
		if (ch == LEFTKEY || ch == 'a')
		{
			player.m_posx--;
			if (player.m_posx <= 1) //경계값을 설정
				player.m_posx = 1; //해당 경계값을 넘을 수 없도록
		}
		if (ch == RIGHTKEY || ch == 'd')
		{
			player.m_posx++;
			if (player.m_posx >= WIDTH - player.m_size)//경계값을 설정
				player.m_posx = WIDTH - player.m_size; //해당 경계값을 넘을 수 없도록
		}
		break;
	case STAGEOVER:
		if (ch == SPACEBAR)
		{
			sceneState = TITLE;
		}
		if (ch == 'q')
		{
			exit(1);
		}
		break;
	}
}
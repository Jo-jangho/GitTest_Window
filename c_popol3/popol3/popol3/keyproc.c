#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "main.h"

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
		if (ch == 32)
			sceneState = MENU;
		break;
	case MENU:
		if (ch == 32)
			sceneState = GAME;
		break;
	case GAME:
		if (ch == LEFTKEY)
		{
			player.m_posx--;
			if (player.m_posx <= 1) //경계값을 설정
				player.m_posx = 1; //해당 경계값을 넘을 수 없도록
		}
		else if (ch == RIGHTKEY)
		{
			player.m_posx++;
			if (player.m_posx >= (WIDTH / 2) - 2)//경계값을 설정
				player.m_posx = (WIDTH / 2) - 2; //해당 경계값을 넘을 수 없도록
		}
		break;
	case STAGECLEAR:
		break;
	case STAGEOVER:
		break;
	}
}
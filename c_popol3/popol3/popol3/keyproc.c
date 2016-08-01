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
			if (player.m_posx <= 1) //��谪�� ����
				player.m_posx = 1; //�ش� ��谪�� ���� �� ������
		}
		else if (ch == RIGHTKEY)
		{
			player.m_posx++;
			if (player.m_posx >= (WIDTH / 2) - 2)//��谪�� ����
				player.m_posx = (WIDTH / 2) - 2; //�ش� ��谪�� ���� �� ������
		}
		break;
	case STAGECLEAR:
		break;
	case STAGEOVER:
		break;
	}
}
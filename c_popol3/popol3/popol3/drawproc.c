#include <stdio.h>
#include "grpengine.h"
#include "main.h"
#include "drawproc.h"

void DrawProcess(int scene)
{
	switch (scene)
	{
	case TITLE:
		t_design();
		break;
	case MENU:
		m_design();
		break;
	case TUTORIAL:
		Tuto();
		break;
	case GAME:
		map_box();
		draw_number();
		DrawStage();
		Ball();
		break;
	case STAGEOVER:
		Ending();
		break;
	}
}

void DrawStage()
{
	gotoxy(2, 3);
	printf("score : %d", player.m_score);
	gotoxy(30, 3);
	printf("time : %ld", MAX_TIME - sec);

	// land draw
	for (int i = 0; i < WIDTH; i++)
	{
		gotoxy(i, HEIGHT);
		printf("-");
	}

	// circle draw
	for (int i = 0; i < D_SIZE; i++)
	{
		if (circle[i].m_isAlive == 1)
			drawchar(&circle[i]);
	}

	// player draw
	drawchar(&player);
}

void drawchar(Creature *cr)
{
	if (cr->m_isAlive == 1)
	{
		gotoxy(cr->m_posx, cr->m_posy);
		SetColor(cr->m_color);
		printf("%s", cr->m_shape);
		SetColor(YELLOW);
	}	
}

void draw_number()
{
	if (gamestate == state_ready)
	{
		//초를 가지고 계산  (logic)
		if (readycount > 0)
		{
			gotoxy((WIDTH / 2) - 2, 5);
			printf("Ready");
			gotoxy(WIDTH / 2, 6);
			printf("%ld", readycount);
		}
		if (readycount <= 0)
		{
			gotoxy((WIDTH / 2) - 2, 7);
			printf("go!!!");
		}
	}
}

void map_box()
{
	for (int i = 1; i < WIDTH; i++)
	{
		gotoxy(i, 1);
		printf("-");
	}

	for (int i = 1; i < HEIGHT; i++)
	{
		gotoxy(0, i);
		printf("│");
	}

	for (int i = 1; i < HEIGHT; i++)
	{
		gotoxy(WIDTH, i);
		printf("│");
	}

	for (int i = 0; i < WIDTH; i++)
	{
		gotoxy(i, HEIGHT);
		printf("-");
	}

	gotoxy(0, 1);
	printf("┌");
	gotoxy(WIDTH, 1);
	printf("┐");
	gotoxy(0, HEIGHT);
	printf("└");
	gotoxy(WIDTH, HEIGHT);
	printf("┘");
}

void t_design()
{
	map_box();
	SetColor(WHITE);
	gotoxy(9, 3);
	printf("#");
	gotoxy(10, 3);
	printf("#");
	gotoxy(11, 3);
	printf("#");
	gotoxy(13, 3);
	printf("#");
	gotoxy(17, 3);
	printf("#");
	gotoxy(18, 3);
	printf("#");
	gotoxy(19, 3);
	printf("#");
	gotoxy(21, 3);
	printf("#");
	gotoxy(23, 3);
	printf("#");
	gotoxy(26, 3);
	printf("#");
	gotoxy(27, 3);
	printf("#");
	gotoxy(28, 3);
	printf("#");
	gotoxy(29, 3);
	printf("#");
	gotoxy(31, 3);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(9, 4);
	printf("#");
	gotoxy(11, 4);
	printf("#");
	gotoxy(13, 4);
	printf("#");
	gotoxy(14, 4);
	printf("#");
	gotoxy(17, 4);
	printf("#");
	gotoxy(21, 4);
	printf("#");
	gotoxy(22, 4);
	printf("#");
	gotoxy(23, 4);
	printf("#");
	gotoxy(29, 4);
	printf("#");
	gotoxy(31, 4);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(9, 5);
	printf("#");
	gotoxy(10, 5);
	printf("#");
	gotoxy(11, 5);
	printf("#");
	gotoxy(13, 5);
	printf("#");
	gotoxy(17, 5);
	printf("#");
	gotoxy(18, 5);
	printf("#");
	gotoxy(19, 5);
	printf("#");
	gotoxy(21, 5);
	printf("#");
	gotoxy(23, 5);
	printf("#");
	gotoxy(29, 5);
	printf("#");
	gotoxy(31, 5);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(21, 6);
	printf("#");
	gotoxy(23, 6);
	printf("#");
	gotoxy(28, 6);
	printf("#");
	gotoxy(31, 6);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(11, 7);
	printf("#");
	gotoxy(12, 7);
	printf("#");
	gotoxy(13, 7);
	printf("#");
	gotoxy(27, 7);
	printf("#");
	gotoxy(31, 7);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(13, 8);
	printf("#");
	gotoxy(31, 8);
	printf("#");
	gotoxy(13, 9);
	printf("#");
	//--------------------------------------------------------------------------
	SetColor(YELLOW);
	gotoxy(23, 9);
	printf("작아져라!");
	for (int i = 2; i < WIDTH; i++)
	{
		SetColor(YELLOW);
		gotoxy(i, 11);
		printf("-");
	}
	SetColor(BLUE);
	gotoxy(11, 17);
	printf("●");
	gotoxy(11, 15);
	printf("│");
	gotoxy(11, 13);
	printf("│");
	SetColor(RED);
	gotoxy(20, 19);
	printf("●");
	gotoxy(20, 17);
	printf("│");
	gotoxy(20, 15);
	printf("│");
	gotoxy(20, 13);
	printf("│");
	SetColor(GREEN);
	gotoxy(29, 15);
	printf("●");
	gotoxy(29, 13);
	printf("│");
	SetColor(WHITE);
	gotoxy(17, 20);
	printf("========");
	SetColor(YELLOW);
	gotoxy(10, 23);
	printf("Please, Coin Insert !!");
}
void Ending()
{
	map_box();
	SetColor(YELLOW);
	gotoxy(16, 7);
	printf("Game Over!");
	gotoxy(14, 11);
	printf("High Score:%d", hi_score);
	gotoxy(14, 13);
	printf("Score:%d", player.m_score);
	for (int i = 8; i < 34; i++)
	{
		gotoxy(i, 9);
		printf("-");
	}
	for (int i = 10; i < 15; i++)
	{
		gotoxy(6, i);
		printf("│");
	}
	for (int i = 10; i < 15; i++)
	{
		gotoxy(34, i);
		printf("│");
	}
	for (int i = 8; i < 34; i++)
	{
		gotoxy(i, 15);
		printf("-");
	}
	gotoxy(6, 9);
	printf("┌");
	gotoxy(34, 9);
	printf("┐");
	gotoxy(6, 15);
	printf("└");
	gotoxy(34, 15);
	printf("┘");
	SetColor(YELLOW);
	gotoxy(6, 22);
	printf("스페이스바를 누르면 처음으로!!");

}
void Tuto()
{
	int b_posx = 0, b_posy = 0;
	int r_posx = 0, r_posy = 10;
	int g_posx = 0, g_posy = 20;
	int s_posx = 0, s_posy = 0, s_state = RIGHT;
	int bLoop = 1;

	while (bLoop)
	{
		ClearScreen();

		char ch = 0;;
		while (kbhit())
		{
			ch = getch();
			if (ch == SPACEBAR)
			{
				bLoop = 0;
				sceneState = MENU;
			}
		}

		SetColor(YELLOW);
		map_box();
		gotoxy(3, 3);
		printf("score:%d", player.m_score);
		gotoxy(29, 3);
		printf("time: %ld. %ld", sec, milsec);


		b_posy++;
		if (b_posy >= HEIGHT - 1)
		{
			b_posy = 1;
		}
		SetColor(BLUE);
		gotoxy(10, b_posy);
		printf("●");


		r_posy++;
		if (r_posy >= HEIGHT - 1)
		{
			r_posy = 1;
		}
		SetColor(RED);
		gotoxy(20, r_posy);
		printf("●");

		g_posy++;
		if (g_posy >= HEIGHT - 1)
		{
			g_posy = 1;
		}
		SetColor(GREEN);
		gotoxy(30, g_posy);
		printf("●");

		switch (s_state)
		{
		case LEFT:
			s_posx--;
			if (s_posx <= 1)
			{
				s_state = RIGHT;
			}
			break;
		case RIGHT:
			s_posx++;
			if (s_posx >= WIDTH - 8)
			{
				s_state = LEFT;
			}
			break;
		}
		SetColor(WHITE);
		gotoxy(1 + s_posx, HEIGHT - 1);
		printf("========");

		Ball();
		SetColor(YELLOW);
		gotoxy(45, 10);
		printf("Menu -> Spacebar");

		Sleeped(100);
	}

}
void m_design()
{
	map_box();
	SetColor(WHITE);
	gotoxy(9, 3);
	printf("#");
	gotoxy(10, 3);
	printf("#");
	gotoxy(11, 3);
	printf("#");
	gotoxy(13, 3);
	printf("#");
	gotoxy(17, 3);
	printf("#");
	gotoxy(18, 3);
	printf("#");
	gotoxy(19, 3);
	printf("#");
	gotoxy(21, 3);
	printf("#");
	gotoxy(23, 3);
	printf("#");
	gotoxy(26, 3);
	printf("#");
	gotoxy(27, 3);
	printf("#");
	gotoxy(28, 3);
	printf("#");
	gotoxy(29, 3);
	printf("#");
	gotoxy(31, 3);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(9, 4);
	printf("#");
	gotoxy(11, 4);
	printf("#");
	gotoxy(13, 4);
	printf("#");
	gotoxy(14, 4);
	printf("#");
	gotoxy(17, 4);
	printf("#");
	gotoxy(21, 4);
	printf("#");
	gotoxy(22, 4);
	printf("#");
	gotoxy(23, 4);
	printf("#");
	gotoxy(29, 4);
	printf("#");
	gotoxy(31, 4);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(9, 5);
	printf("#");
	gotoxy(10, 5);
	printf("#");
	gotoxy(11, 5);
	printf("#");
	gotoxy(13, 5);
	printf("#");
	gotoxy(17, 5);
	printf("#");
	gotoxy(18, 5);
	printf("#");
	gotoxy(19, 5);
	printf("#");
	gotoxy(21, 5);
	printf("#");
	gotoxy(23, 5);
	printf("#");
	gotoxy(29, 5);
	printf("#");
	gotoxy(31, 5);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(21, 6);
	printf("#");
	gotoxy(23, 6);
	printf("#");
	gotoxy(28, 6);
	printf("#");
	gotoxy(31, 6);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(11, 7);
	printf("#");
	gotoxy(12, 7);
	printf("#");
	gotoxy(13, 7);
	printf("#");
	gotoxy(27, 7);
	printf("#");
	gotoxy(31, 7);
	printf("#");
	//--------------------------------------------------------------------------
	gotoxy(13, 8);
	printf("#");
	gotoxy(31, 8);
	printf("#");
	gotoxy(13, 9);
	printf("#");
	//--------------------------------------------------------------------------

	for (int i = 2; i < WIDTH; i++)
	{
		SetColor(YELLOW);
		gotoxy(i, 11);
		printf("-");
	}
	SetColor(BLUE);
	gotoxy(11, 15);
	printf("●");
	SetColor(RED);
	gotoxy(20, 17);
	printf("●");
	SetColor(GREEN);
	gotoxy(29, 13);
	printf("●");
	SetColor(WHITE);
	gotoxy(17, 18);
	printf("========");
	SetColor(YELLOW);
	gotoxy(10, 20);
	printf("Game Start -> Spacebar");
	gotoxy(10, 22);
	printf("Tutorial -> T");
}

void Ball()
{
	SetColor(BLUE);
	gotoxy(45, 4);
	printf("● : 50점");
	SetColor(RED);
	gotoxy(45, 6);
	printf("● : 100점");
	SetColor(GREEN);
	gotoxy(45, 8);
	printf("● : 150점");
}
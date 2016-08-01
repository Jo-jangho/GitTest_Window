#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

#ifndef __GRPENGINE_H_
#define __GRPENGINE_H_

void ClearScreen();
void Sleeped(int mil_second);
void SetColor(unsigned short color);
void gotoxy(int x, int y);

#endif
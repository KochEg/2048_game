#include <iostream>
#include <Windows.h>
#include "Screen_class.h"

void Screen_class::SetEnd()
{
	screen[screen_Height - 1][screen_Width - 1] = '\0';
}

void Screen_class::SetCursorPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Screen_class::Screen_class()
{
	Clear();
}

void Screen_class::Clear()
{
	memset(screen, ' ', sizeof(screen));
}

void Screen_class::Show()
{
	SetCursorPosition(0, 0);
	SetEnd();
	std::cout << screen[0];
}




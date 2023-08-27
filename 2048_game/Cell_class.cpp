#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Cell_class.h"

Cell_class::Cell_class()
{
	Init(0, 0, 0);
}

void Cell_class::Init(int x, int y, int value)
{
	this->value = value;
	this->pos.x = x;
	this->pos.y = y;
}

void Cell_class::Put(ScreenMap_type scr)
{
	for (int i = 0; i < cell_Width; i++)
		for (int j = 0; j < cell_Height; j++)
			scr[pos.y + j][pos.x + i] = (i == 0 || i == cell_Width - 1 || j == 0 || j == cell_Height - 1) ? '+' : ' ';

	if (value == 0) return;
	char buf[10];
	sprintf(buf, "%d", value);
	int len = strlen(buf);
	int posX = (cell_Width - len) / 2;
	int posY = (cell_Height - 1) / 2;
	for (int i = 0; i < len; i++)
		scr[pos.y + posY][pos.x + i + posX] = buf[i];
}

void Cell_class::SetValue(int val)
{
	this->value = val;
}

int Cell_class::GetValue()
{
	return value;
}

#include "Game_class.h"

bool Game_class::MoveValueInArray(AnimatedCell_class* valueArray[], int count)
{
	bool moved = false;
	int lastX = 0;
	for (int i = 1; i < count; i++)
		if (valueArray[i]->GetValue() != 0)
		{
			if (valueArray[lastX]->GetValue() == 0)
			{
				valueArray[i]->Animation(valueArray[lastX]->GetFullPos());
				valueArray[lastX]->Animation(valueArray[lastX]->GetFullPos());
				moved = true;
				valueArray[lastX]->SetValue(valueArray[i]->GetValue());
				valueArray[i]->SetValue(0);
			}
			else if (valueArray[lastX]->GetValue() == valueArray[i]->GetValue())
			{
				valueArray[i]->Animation(valueArray[lastX]->GetFullPos());
				valueArray[lastX]->Animation(valueArray[lastX]->GetFullPos());
				moved = true;
				valueArray[lastX]->SetValue(valueArray[lastX]->GetValue() + valueArray[i]->GetValue());
				valueArray[i]->SetValue(0);
				lastX++; 
			}
			else if (valueArray[lastX]->GetValue() != valueArray[i]->GetValue())
			{
				lastX++;
				if (lastX != i)
				{
					valueArray[i]->Animation(valueArray[lastX]->GetFullPos());
					valueArray[lastX]->Animation(valueArray[lastX]->GetFullPos());
					moved = true;
					valueArray[lastX]->SetValue(valueArray[i]->GetValue());
					valueArray[i]->SetValue(0);
				}
			}
		}
	return moved;
}

void Game_class::Move(int x, int y)
{
	bool moved = false;
	if (x != 0)
		for (int j = 0; j < field_Height; j++)
		{
			AnimatedCell_class*valueArray[field_Wigth];
			for (int i = 0; i < field_Wigth; i++)
			{
				int i2 = (x < 0) ? i : field_Wigth - i - 1;
				valueArray[i] = &cell[j][i2]; /*в массив указателей на клеточки записываем адреса всех клеточек строки*/
			}
			if (MoveValueInArray(valueArray, field_Wigth)) moved = true;
		}
	if (y != 0)
		for (int i = 0; i < field_Wigth; i++)
		{
			AnimatedCell_class* valueArray[field_Height];
			for (int j = 0; j < field_Height; j++)
			{
				int j2 = (y < 0) ? j : field_Height - j - 1;
				valueArray[j] = &cell[j2][i]; /*в массив указателей на клеточки записываем адреса всех клеточек столбцов*/
			}
			if (MoveValueInArray(valueArray, field_Height)) moved = true;
		}
	if (ChackEndGame()) Init();
	else if (moved) GenerationNewRandomNumbers();
}

bool Game_class::KeyDownOnce(char c) /*?*/
{
	if (GetKeyState(c) < 0)
	{
		while (GetKeyState(c) < 0)
		return true;
	}
	return false;
}

void Game_class::GenerationNewRandomNumbers()
{
	if (GenFreeCellCount() == 0) return;
	int count = 1;
	while (count > 0)
	{
		int x = rand() % field_Wigth;
		int y = rand() % field_Height;
		if (cell[x][y].GetValue() == 0)
		{
			cell[x][y].SetValue((rand()%10 == 0) ? 4 : 2); /*4 генерируется в 10% случаев*/
			count--;
		}
	}
}

int Game_class::GenFreeCellCount()
{
	int count = 0;
	for (int i = 0; i < field_Wigth * field_Height; i++)
		if (cell[0][i].GetValue() == 0)
			count++;
	return count;
}

bool Game_class::ChackEndGame()
{
	if (GenFreeCellCount() > 0) return false;
	for (int i = 0; i < field_Wigth; i++)
		for (int j = 0; j < field_Height; j++)
			if ((j < field_Height - 1 && cell[j][i].GetValue() == cell[j + 1][i].GetValue()) ||
				(i < field_Wigth - 1 && cell[j][i].GetValue() == cell[j][i + 1].GetValue()))
				return false;
	return true;
}

Game_class::Game_class()
{
	Init();
}

void Game_class::Init()
{
	const int startX = 2;
	const int startY = 2;
	srand(GetTickCount64());
	for (int i = 0; i < field_Wigth; i++)
		for (int j = 0; j < field_Height; j++)
			cell[j][i].Init(startX + i * (cell_Width - 1), startY + j * (cell_Height - 1), 0);

	GenerationNewRandomNumbers();
	GenerationNewRandomNumbers();
}

void Game_class::Show()
{
	for (int i = 0; i < field_Wigth; i++)
		for (int j = 0; j < field_Height; j++)
			cell[j][i].Put(scr.screen);
	for (int i = 0; i < field_Wigth; i++)
		for (int j = 0; j < field_Height; j++)
			cell[j][i].PutAnimation(scr.screen);
	scr.Show();
}

void Game_class::Work()
{
	if (KeyDownOnce('W')) Move(0, -1);
	if (KeyDownOnce('S')) Move(0, 1);
	if (KeyDownOnce('A')) Move(-1, 0);
	if (KeyDownOnce('D')) Move(1, 0);
	/*if (GetKeyState('A') < 0) Move(-1, 0);*/
}

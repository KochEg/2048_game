#pragma once
#include "Screen_class.h"
#include "AnimatedCell_class.h"

class Game_class
{
private:
	Screen_class scr;
	AnimatedCell_class cell[field_Height][field_Wigth];
	bool MoveValueInArray(AnimatedCell_class* valueArray[], int count);
	void Move(int x, int y);
	bool KeyDownOnce(char c); /*?*/
	void GenerationNewRandomNumbers();
	int GenFreeCellCount();
	bool ChackEndGame();
public:
	Game_class();
	void Init();
	void Show();
	void Work();
};


#pragma once
#include <Windows.h>
#include "Constans.h"

class Cell_class
{
private:
	int value;
	POINT pos;
public:
	Cell_class();
	void Init(int x, int y, int value);
	void Put(ScreenMap_type scr);
	void SetValue(int val);
	int GetValue();
	int GetPosX() { return pos.x; }
	int GetPosY() { return pos.y; }
	POINT GetFullPos() { return pos; }
};


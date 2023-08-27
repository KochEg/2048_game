#pragma once
#include "Constans.h"

class Screen_class
{
private:
	void SetEnd();
	void SetCursorPosition(int x, int y);
public:
	ScreenMap_type screen;
	Screen_class();
	void Clear();
	void Show();
};


#pragma once
#include "Cell_class.h"

class AnimatedCell_class : public Cell_class
{
private:
	float startX, startY;
	float everyStepX, everyStepY;
	int countOfStep;
	int cellValueInMotion;
public:
	AnimatedCell_class() :Cell_class() { countOfStep = 0; }
	void Animation(POINT to);
	bool IsAnimation();
	void Work();
	void PutAnimation(ScreenMap_type scr);
};


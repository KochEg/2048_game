#include <cmath>
#include "AnimatedCell_class.h"

void AnimatedCell_class::Animation(POINT to)
{
	if (IsAnimation()) return;
	cellValueInMotion = GetValue();
	startX = GetPosX();
	startY = GetPosY();
	everyStepX = (to.x - startX) / (float)countOfStep;
	everyStepY = (to.y - startY) / (float)countOfStep;
}

bool AnimatedCell_class::IsAnimation()
{
	return countOfStep > 0 ? true : false;
}

void AnimatedCell_class::Work()
{
	countOfStep--;
	startX += everyStepX;
	startY += everyStepY;
}

void AnimatedCell_class::PutAnimation(ScreenMap_type scr)
{
	if (IsAnimation())
	{
		Work();
		Cell_class cell;
		cell.Init(lround(startX), lround(startY), cellValueInMotion);
		cell.Put(scr);
	}
}

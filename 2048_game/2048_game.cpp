#include <iostream>
#include "Screen_class.h"
#include "Cell_class.h"
#include "Game_class.h"

int main()
{
	Game_class game;
	while (1)
	{
		game.Work();
		game.Show();
		if (GetKeyState(VK_ESCAPE) < 0) break;
		Sleep(120);
	}
	return 0;
}


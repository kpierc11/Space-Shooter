#include "Game.h"
#include <iostream>

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "hello World";
	Game game;
	bool success = game.Initialize();

	if (success)
	{
		game.GameLoop();
	}

	game.EndGame();

	return 0;
}
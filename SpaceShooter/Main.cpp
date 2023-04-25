#include "Game.h"


int main(int argc, char** argv) {

	Game game;

	bool success = game.Initialize();

	if (success) {
		game.GameLoop();
	}

	game.EndGame();

  
	return 0;
}
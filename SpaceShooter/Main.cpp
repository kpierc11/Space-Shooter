#include "Game.h"


int main(int argc, char** argv) {

	//Instantiate Game
	Game game;

	//Store the result of initialize game
	bool success = game.Initialize();

	if (success) {
		game.GameLoop();
	}

	game.EndGame();


	return 0;
}
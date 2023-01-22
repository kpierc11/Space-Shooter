#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <string>
#include <vector>


class Game
{
public:
	//default constructor 
	Game();

	//destructor 
	~Game();

	bool Initialize();

	void GameLoop();

	void HandleInput();

	void UpdateGame();

	void GenerateOutput();

	SDL_Texture* LoadTexture(const std::string& fileName);
	void AddActors(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSpriteComponent(class SpriteComponent* spriteComponent);
	void RemoveSpriteComponent(class SpriteComponent* spriteComponent);
	void UnloadData();
	void EndGame();

private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mGameRunning;
	bool mKeyDown;
	std::vector<class Actor*> mActors;
	std::vector<class SpriteComponent*> mSpriteComponents;
};




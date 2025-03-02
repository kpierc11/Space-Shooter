#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

struct WindowSize {
	float width; 
	float height;
};

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
	SDL_Texture* LoadEmptyTexture(int width, int height);
	WindowSize GetWindowSize() const { return mWindowSize; };
	SDL_Renderer* GetRenderer() { return mRenderer; };

	void AddActors(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSpriteComponent(class SpriteComponent* spriteComponent);
	void RemoveSpriteComponent(class SpriteComponent* spriteComponent);
	void UnloadData();
	void EndGame();


private:
	SDL_Window* mWindow;
	WindowSize mWindowSize;
	SDL_Renderer* mRenderer;
	class GameLevel* mLevel;
	bool mGameRunning;
	bool mKeyDown;
	std::vector<class Actor*> mActors;
	std::vector<class SpriteComponent*> mSpriteComponents;
};




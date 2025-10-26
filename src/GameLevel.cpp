#include "GameLevel.h"
#include "Ship.h"
#include "Game.h"
#include <chrono>
#include <thread>

using namespace GameMath;

GameLevel::GameLevel(class Game* game) :mGame(game), mAsteroids({}), mLevelBackground(NULL), mLevelBackgroundActor(NULL)
{

}


GameLevel::~GameLevel() {
	std::cout << "Game Level Destroyed" << std::endl;
}


void GameLevel::InitLevel() {
	//ship
	Ship* shipActor = new Ship(mGame);
	shipActor->SetPosition({ mGame->GetWindowSize().height / 2,  mGame->GetWindowSize().width / 2 });
	shipActor->SetScale(2);

	mLevelBackgroundActor = new Actor(mGame);
	mLevelBackgroundActor->SetPosition(Vector2(512.0f, 384.0f));

	// Create the "far back" background
	mLevelBackground = new BGSpriteComponent(mLevelBackgroundActor);
	mLevelBackground->SetScreenSize(Vector2(1024.0f, 768.0f));
	std::vector<SDL_Texture*> bgtexs = {
		mGame->LoadTexture("Assets/space-bg.png"),
		mGame->LoadTexture("Assets/space-bg.png")
	};
	mLevelBackground->SetBGTextures(bgtexs);
	mLevelBackground->SetScrollSpeed(-100.0f);

	//SDL_RenderDrawLine(mGame->GetRenderer(), 0, 0, 768, 300);

	//Initial Font Type
	//TTF_Font* font = TTF_OpenFont("assets/fonts/arial.ttf", 25);

	//color 
	SDL_Color color = { 255,255,255 };

	//Score
	Actor* highScoreActor = new Actor(mGame);
	highScoreActor->SetPosition({ 100 , 30 });
	highScoreActor->SetScale(2);

	SpriteComponent* highScore = new SpriteComponent(highScoreActor,30);

	//SDL_Surface* highScoreSurface = TTF_RenderText_Solid(font, "Score: ", color);

	//SDL_Texture* highScoreTexture = SDL_CreateTextureFromSurface(mGame->GetRenderer(), highScoreSurface);

	//highScore->SetTexture(highScoreTexture);


	//free font resource
	//TTF_CloseFont(font);


}

void GameLevel::GenerateAsteroid(float speed, float size)
{
	float ranSpeed = float(rand()) / float(RAND_MAX) * speed + 10;
	float ranSize = (float(rand()) / float(RAND_MAX) * size + 1);
	std::cout << ranSize << "\n";
	Asteroid* asteroid = new Asteroid(mGame);
	asteroid->SetScale(ranSize);
	asteroid->SetFallSpeed(ranSpeed);
	mAsteroids.push_back(asteroid);
}


void GameLevel::UpdateLevel() {

	/*int level = 1;
	if (level == 1) {

		if (mAsteroids.size() <= 10) {
			GenerateAsteroid(200.0f, 4.0f);	
		}
	
		for (auto asteroid : mAsteroids) {
			if (asteroid->GetPosition().y >= mGame->GetWindowSize().height) {
				delete asteroid;
			}
		}
		
	}
	else if (level == 2) {

		if (mAsteroids.size() < 20) {
			GenerateAsteroid(40, 3.0);
		}

		for (auto asteroid : mAsteroids) {
			if (asteroid->GetPosition().y >= mGame->GetWindowSize().height) {
				delete asteroid;
			}
		}
	}*/

}





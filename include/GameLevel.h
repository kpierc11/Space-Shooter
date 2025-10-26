#pragma once
#include <vector>
#include "Asteroid.h"
#include "BGSpriteComponent.h"
#include "GameMath.h"
class GameLevel
{
public:
	GameLevel(class Game* game);
	~GameLevel();
	void InitLevel();
	void UpdateLevel();
	void GenerateAsteroid(float speed, float size);

private:
	std::vector<Asteroid*> mAsteroids;
	Actor* mLevelBackgroundActor;
	BGSpriteComponent* mLevelBackground;
	Game* mGame;
	int mCount;
};


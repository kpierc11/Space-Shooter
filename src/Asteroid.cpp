#include "Asteroid.h"
#include "SpriteComponent.h"
#include "GameMath.h"
#include "Game.h"
#include <iostream>

using namespace GameMath;

Asteroid::Asteroid(Game* game):Actor(game)
{
	SpriteComponent* asteroidSprite = new SpriteComponent(this, 29);
    asteroidSprite->SetTexture(game->LoadTexture("assets/PixelSpaceRage/128px/Asteroid 01_png_processed.png"));
    int randomX = rand() % 1023;
    int randomY = rand() % 767;
    this->SetPosition(GameMath::Vector2(randomX, randomY - 768));
}

Asteroid::~Asteroid()
{
    printf("Asteroid Destroyed\n");
}

void Asteroid::Update(float deltaTime)
{

    Vector2 currentAsteroidPos = GetPosition();

    Vector2 move = { 0.0f , mFallSpeed * deltaTime };

    Vector2 newPos = currentAsteroidPos + move;
 
    SetPosition(newPos);
}


void Asteroid::SetFallSpeed(float fallSpeed) {

    mFallSpeed = fallSpeed;
}

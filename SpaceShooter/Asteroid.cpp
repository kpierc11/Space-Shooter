#include "Asteroid.h"
#include "SpriteComponent.h"
#include "GameMath.h"

using namespace GameMath;

Asteroid::Asteroid(Game* game)
	:Actor(game)
{
	SpriteComponent* asteroidSprite = new SpriteComponent(this);
    asteroidSprite->SetTexture(game->LoadTexture("Assets/meteorite.png"));
    int randomX = rand() % 1024;
    int randomY = rand() % 768;
    this->SetPosition(GameMath::Vector2(randomX, randomY - 768));
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(float deltaTime)
{

    Vector2 currentAsteroidPos = GetPosition();

    SetPosition({ currentAsteroidPos.x , currentAsteroidPos.y + mFallSpeed * deltaTime });
}


void Asteroid::SetFallSpeed(float fallSpeed) {

    mFallSpeed = fallSpeed;
}

#include "Bullet.h"
#include "Ship.h"
#include "SpriteComponent.h"
#include "GameMath.h"
#include "Game.h"

Bullet::Bullet(Game *game, Ship *ship)
	: Actor(game),
	  mShip(ship)
{
	SpriteComponent *bullet = new SpriteComponent(this, 18);
	SDL_Texture *text = this->GetGame()->LoadTexture("assets/PixelSpaceRage/128px/Plasma_Medium_png_processed.png");
	bullet->SetTexture(text);
	this->SetScale(1);
	mState = BulletState::Active;
}

Bullet::~Bullet()
{
	printf("bullet died\n");
}

void Bullet::Update(float deltaTime)
{

	GameMath::Vector2 bulletPosition = GetPosition();
	float speed = 800.0f;

	if (mState == BulletState::Inactive)
	{
		SetPosition(mShip->GetPosition());
	}

	if (mState == BulletState::Active)
	{
		SetPosition({bulletPosition.x, bulletPosition.y - speed * deltaTime});
	}

	if (bulletPosition.y <= 0)
	{
		mState = BulletState::Inactive;
		SetPosition(mShip->GetPosition());
	}
}

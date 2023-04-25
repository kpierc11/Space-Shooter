#include "Bullet.h"
#include "Ship.h"
#include "SpriteComponent.h"


Bullet::Bullet(Game* game, Ship* ship)
	:Actor(game),
	mShip(ship),
	mShootBullet(false)
{
	SpriteComponent* bullet = new SpriteComponent(this,18);
	SDL_Texture* text = this->GetGame()->LoadTexture("assets/bullet.png");
	bullet->SetTexture(text);
	this->SetScale(2);
}

Bullet::~Bullet()
{
	printf("bullet died\n");
}

void Bullet::Update(float deltaTime)
{

	Vector2 bulletPosition = GetPosition();
	float speed = 800.0f;

	if (!mShootBullet) {
		SetPosition(mShip->GetPosition());
	}
	else if (mShootBullet) {
		SetPosition({ bulletPosition.x, bulletPosition.y - speed * deltaTime });
	}
	 

}




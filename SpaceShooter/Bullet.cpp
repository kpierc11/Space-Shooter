#include "Bullet.h"
#include "Ship.h"

Bullet::Bullet(Game* game, Ship* ship)
	:Actor(game),
	mShip(ship)
{

}

Bullet::~Bullet()
{
	printf("bullet died");
}

void Bullet::Update(float deltaTime)
{

	Vector2 bulletPosition = GetPosition();
	float speed = 800.0f;

	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

	if (keyboardState[SDL_SCANCODE_SPACE]) {
		mShootBullet = true;
	}

	SetPosition(mShip->GetPosition());

	if (mShootBullet) {

		SetPosition({ bulletPosition.x, bulletPosition.y - speed * deltaTime });
	}


}


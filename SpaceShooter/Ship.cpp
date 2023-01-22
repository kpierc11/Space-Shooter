#include "Ship.h"
#include <iostream>
#include "SpriteComponent.h"
#include "Bullet.h"

Ship::Ship(Game* game)
	:Actor(game)
{
}

Ship::~Ship()
{
}

void Ship::Update(float deltaTime)
{
	Vector2 playerPosition = GetPosition();
	float speed = 800.0f;

	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_D]) {

		//move right
		SetPosition({ playerPosition.x + speed * deltaTime, playerPosition.y });
	}
	else if (keyboardState[SDL_SCANCODE_A]) {

		//move left
		SetPosition({ playerPosition.x - speed * deltaTime, playerPosition.y });
	}
	else if (keyboardState[SDL_SCANCODE_W]) {

		//move forward
		SetPosition({ playerPosition.x , playerPosition.y - speed * deltaTime });
	}
	else if (keyboardState[SDL_SCANCODE_S]) {

		//move backwards
		SetPosition({ playerPosition.x, playerPosition.y + speed * deltaTime });
	}

	if (keyboardState[SDL_SCANCODE_SPACE]) {
		mShootBullet = true;
	}

	if (mShootBullet) {
		Bullet* bullet = new Bullet(this->GetGame(), this);
		bullet->SetPosition(this->GetPosition());
		bullet->SetScale(2);

		SDL_Texture* bulletTex = this->GetGame()->LoadTexture("assets/bullet.png");

		SpriteComponent* bulletSprite = new SpriteComponent(bullet);
		bulletSprite->SetTexture(bulletTex);
		bulletSprite->SetTextureHeight(32);
		bulletSprite->SetTextureWidth(32);

		this->GetGame()->AddSpriteComponent(bulletSprite);

		mBullets.push_back(bullet);

		FireBullet(deltaTime);
	}
}

void Ship::HandleInput(const Uint8* keyboardState, bool keyDown)
{
	if (keyboardState[SDL_SCANCODE_D]) {

	}
}

void Ship::FireBullet(float deltaTime)
{
	for (auto bullet : mBullets) {
		float speed = 800.0f;
		Vector2 bulletPosition = bullet->GetPosition();

		bullet->SetPosition({ bulletPosition.x, bulletPosition.y - speed * deltaTime });

	}
}



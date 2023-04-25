#include <iostream>
#include "Ship.h"
#include "SpriteComponent.h"
#include "Bullet.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mShootBullet(false)
	,mAmmoCount(499)
{
	SpriteComponent* ship = new SpriteComponent(this, 30);
	SDL_Texture* text = this->GetGame()->LoadTexture("assets/ship-3.png");
	ship->SetTexture(text);

	for (int i = 0; i < 500; i++) {

		Bullet* bullet = new Bullet(this->GetGame(), this);
		mBullets.push_back(bullet);
	}

}

Ship::~Ship()
{
	
}

void Ship::Update(float deltaTime)
{
	Vector2 playerPosition = GetPosition();
	float speed = 800.0f;

	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_D] && playerPosition.x <= (1024 -32)) {

		//move right
		SetPosition({ playerPosition.x + speed * deltaTime, playerPosition.y });
	}
	else if (keyboardState[SDL_SCANCODE_A] && playerPosition.x >= 32) {

		//move left
		SetPosition({ playerPosition.x - speed * deltaTime, playerPosition.y });
	}
	else if (keyboardState[SDL_SCANCODE_W] && playerPosition.y > 32) {

		//move forward
		SetPosition({ playerPosition.x , playerPosition.y - speed * deltaTime });
	}
	else if (keyboardState[SDL_SCANCODE_S] && playerPosition.y <= (768-32)) {

		//move backwards
		SetPosition({ playerPosition.x, playerPosition.y + speed * deltaTime });
	}

	if (mShootBullet) {
		FireBullet();
		mAmmoCount--;
	}



}

void Ship::HandleInput(const Uint8* keyboardState, bool keyDown)
{
	if (keyboardState[SDL_SCANCODE_SPACE]) {
		mShootBullet = true;
	}
	else {
		mShootBullet = false;
	}
}

void Ship::FireBullet()
{
	std::cout << "bullet fired" << std::endl;
	mBullets[mAmmoCount]->FireBullet(true);

}




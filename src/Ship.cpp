#include <iostream>
#include "Ship.h"
#include "SpriteComponent.h"
#include "Bullet.h"
#include "Game.h"

Ship::Ship(Game* game)
	:Actor(game)
	, mBullets({})
	, mBullet(NULL)
	, mShootBullet(false)
	, mAmmoCount(6)
	, mShipRotation(1.0f)

{
	SpriteComponent* ship = new SpriteComponent(this, 30);
	SDL_Texture* text = this->GetGame()->LoadTexture("assets/ship-6.png");
	ship->SetTexture(text);

	// for (int i = 0; i < mAmmoCount + 1; i++) {

	// 	Bullet* bullet = new Bullet(this->GetGame(), this);
	// 	mBullets.push_back(bullet);
	// }
}

Ship::~Ship()
{

}

void Ship::Update(float deltaTime)
{
	GameMath::Vector2 playerPosition = GetPosition();
	float speed = 800.0f;
	Game* game = this->GetGame();
	// const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
	// if (keyboardState[SDL_SCANCODE_D] && playerPosition.x <= (game->GetWindowSize().width - 32))
	// {

	// 	//move right
	// 	SetPosition({ playerPosition.x + speed * deltaTime, playerPosition.y });
	// }
	// if (keyboardState[SDL_SCANCODE_A] && playerPosition.x >= 32)
	// {

	// 	//move left
	// 	SetPosition({ playerPosition.x - speed * deltaTime, playerPosition.y });
	// }
	// if (keyboardState[SDL_SCANCODE_W] && playerPosition.y > 32)
	// {

	// 	//move forward
	// 	SetPosition({ playerPosition.x , playerPosition.y - speed * deltaTime });
	// }
	// if (keyboardState[SDL_SCANCODE_S] && playerPosition.y <= (game->GetWindowSize().height - 32))
	// {

	// 	//move backwards
	// 	SetPosition({ playerPosition.x, playerPosition.y + speed * deltaTime });
	// }
	// if (keyboardState[SDL_SCANCODE_SPACE])
	// {
	// 	FireBullet();
	// 	if (mAmmoCount != 0)
	// 	{
	// 		mAmmoCount--;
	// 	}
	// 	else if (mAmmoCount == 0) {
	// 		ReloadBullets();
	// 	}

	// 	std::cout << "Ammo Count: " << mAmmoCount << "\n";
	// }

}

void Ship::FireBullet()
{
	if (!mBullets.empty()) {
		mBullets[mAmmoCount]->FireBullet(true);
	}
}

void Ship::ReloadBullets()
{

	SetAmmoCount(6);

}

void Ship::SetAmmoCount(int ammoCount)
{
	mAmmoCount = ammoCount;
}



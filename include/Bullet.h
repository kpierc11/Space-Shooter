#pragma once
#include "Actor.h"
#include <iostream>

enum  BulletState
{
	Active,
	Inactive
};

class Bullet : public Actor
{
public:
	Bullet(Game *game, class Ship *ship);
	~Bullet();

	void Update(float deltaTime);

	Ship *mShip;
	BulletState mState;
};

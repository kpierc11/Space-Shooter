#pragma once
#include "Actor.h"
#include <iostream>

class Bullet : public Actor
{
public:
	Bullet(Game* game, class Ship* ship);
	~Bullet();

	void Update(float deltaTime) override;
	void FireBullet(bool shootBullet) { mShootBullet = shootBullet; }

	Ship* mShip;
	bool mShootBullet;
};

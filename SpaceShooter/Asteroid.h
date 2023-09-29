#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
	Asteroid(Game* game);
	~Asteroid();
	void Update(float deltaTime) override;
	void SetFallSpeed(float fallSpeed);


private:
	float mFallSpeed;
};


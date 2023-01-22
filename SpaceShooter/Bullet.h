#pragma
#include "Actor.h"
class Bullet : public Actor
{
public:
	Bullet(Game* game, class Ship* ship);
	~Bullet();

	void Update(float deltaTime) override;

private:
	bool mShootBullet = false;
	Ship* mShip;
};

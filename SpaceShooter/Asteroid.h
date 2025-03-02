#include "Actor.h"

class Asteroid : public Actor
{
public:
	Asteroid(class Game* game);
	~Asteroid();
	void Update(float deltaTime);
	void SetFallSpeed(float fallSpeed);


private:
	float mFallSpeed;
};


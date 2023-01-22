#pragma once
#include "Actor.h"
class Ship : public Actor
{
public:
    Ship(Game* game);
    ~Ship();
    void Update(float deltaTime);
    void HandleInput(const Uint8* keyboardState, bool keyDown) override;
    void FireBullet(float deltaTime);
private:
    bool mShootBullet = false;
    std::vector<class Bullet*> mBullets;
};




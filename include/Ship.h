#pragma once
#include "Actor.h"
#include "Bullet.h"

class Ship : public Actor
{
public:
    Ship(Game* game);
    ~Ship();
    void Update(float deltaTime) override;
    void FireBullet();
    void ReloadBullets();
    void SetAmmoCount(int ammoCount);
private:
    std::vector<Bullet*> mBullets;
    Bullet* mBullet;
    bool mShootBullet;
    int mAmmoCount;
    float mShipRotation;
};




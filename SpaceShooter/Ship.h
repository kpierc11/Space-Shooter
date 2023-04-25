#include "Actor.h"
#include "Bullet.h"

class Ship : public Actor
{
public:
    Ship(Game* game);
    ~Ship();
    void Update(float deltaTime) override;
    void HandleInput(const Uint8* keyboardState, bool keyDown) override;
    void FireBullet();
private:
    std::vector<class Bullet*> mBullets;
    Bullet* mBullet;
    bool mShootBullet;
    int mAmmoCount;
};




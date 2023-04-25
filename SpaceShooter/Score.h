#pragma once
#include "Actor.h"
class Score :
    public Actor
{
public:
    Score(Game* game);
    ~Score();

    void Update(float deltaTime);

private:
    int mScore;
};


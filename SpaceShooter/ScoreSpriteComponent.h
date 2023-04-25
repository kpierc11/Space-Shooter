#pragma once
#include "SpriteComponent.h"
class ScoreSpriteComponent :
    public SpriteComponent
{
    ScoreSpriteComponent();
    ~ScoreSpriteComponent();

    void DisplayScore();
};


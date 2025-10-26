#pragma once
#include "Component.h"
#include "GameMath.h"
class CircleComponent :
    public Component
{
public: 
    CircleComponent(class Actor* owner, int drawOrder = 100);
    ~CircleComponent();

    void SetRadius(float radius) { mRadius = radius; }
    float GetRadius() const { return mRadius; }

    void CheckCollision();
  
  

    float mRadius; 
    
};
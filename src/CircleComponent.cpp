#include "CircleComponent.h"

using namespace GameMath;

CircleComponent::CircleComponent(Actor* owner, int drawOrder)
	:Component(owner),
	mRadius(3)
{
}


CircleComponent::~CircleComponent()
{
}


void CircleComponent::CheckCollision()
{

}



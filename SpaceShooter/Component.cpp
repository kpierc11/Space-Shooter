#include "Component.h"
#include "Actor.h"
#include <iostream>

Component::Component(Actor* actor, int updateOrder)
{
	mOwner = actor;
	mUpdateOrder = updateOrder;
}

Component::~Component()
{
	std::cout << "Component Deleted Yayyyy";
}

void Component::Update(float deltaTime)
{
}
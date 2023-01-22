#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game)
	:mGame(game)
	, mPosition()
	, mRotation()
	, mScale()

{
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	printf("Actor Destroyed");
}

void Actor::AddComponent(Component* component)
{
}

void Actor::Update(float deltaTime)
{
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	}
}

void Actor::AddComponents(Component* component)
{
	mComponents.push_back(component);
}

void Actor::RemoveComponent(Component* component)
{

}

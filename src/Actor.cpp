#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>
#include <iostream>

using namespace GameMath;

Actor::Actor(Game *game)
	: mGame(game), mPosition(), mScale(), mRotation()

{
	mGame->AddActors(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	std::cout<< "Actors Destroyed" << "\n";
}

void Actor::AddComponent(Component *component)
{
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}
	mComponents.insert(iter, component);
}

void Actor::Update(float deltaTime)
{
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::AddComponents(Component *component)
{
	mComponents.push_back(component);
}

void Actor::RemoveComponent(Component *component)
{
}

#pragma once
#include "Game.h"
#include "GameMath.h"

class Actor
{
public:
	Actor(class Game* game);
	virtual ~Actor();

	void AddComponent(class Component* component);
	virtual void Update(float deltaTime);

	//getters 
	GameMath::Vector2 GetPosition() { return mPosition; }
	void SetPosition(const GameMath::Vector2& position) { mPosition = position; }
	float GetScale() { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() { return mRotation; }
	class Game* GetGame() { return mGame; }
	virtual void HandleInput(const Uint8* keyboardState, bool keyDown) {};

	void AddComponents(class Component* component);
	void RemoveComponent(class Component* component);


private:


	class Game* mGame;

	//transform data
	GameMath::Vector2 mPosition;

	float mScale;

	float mRotation;

	//array of components
	std::vector<class Component*> mComponents;


};


#pragma once
#include "GameMath.h"
#include <vector>

class Actor
{
public:
	Actor(class Game* game);
	virtual ~Actor();

	void AddComponent(class Component* component);
	virtual void Update(float deltaTime);

	GameMath::Vector2 GetPosition() const { return mPosition; }
	void SetPosition(const GameMath::Vector2& position) { mPosition = position; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation;}
	class Game* GetGame() { return mGame; }
	virtual void HandleInput(const uint8_t* keyboardState, bool keyDown) {};

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


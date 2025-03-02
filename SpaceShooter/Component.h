#pragma once
#include "Actor.h"
class Component
{
public:

	//default constructor 
	Component(class Actor* owner, int updateOrder = 10);

	//destructor 
	virtual ~Component();

	//update the component by delta time 
	virtual void Update(float deltaTime);

	int GetUpdateOrder() const { return mUpdateOrder; }

protected:

	//Owning Actor
	class Actor* mOwner;

	//update order of component
	int mUpdateOrder;


};




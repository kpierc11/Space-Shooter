#pragma once
#include "SDL3/SDL_render.h"
#include <stdio.h>
#include "Component.h"

class SpriteComponent : public Component
{

public:
	SpriteComponent(class Actor* owner, int drawOrder = 100);

	~SpriteComponent();

	virtual void Draw(SDL_Renderer* renderer);

	virtual void SetTexture(SDL_Texture* texture);
	int GetTextureHeight() { return mTextureHeight; }
	void SetTextureWidth(float width) { mTextureWidth = width; }
	float GetTextureWidth() { return mTextureWidth; }
	void SetTextureHeight(float height) { mTextureWidth = height; }
	int GetDrawOrder() { return mDrawOrder; }




protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	float mTextureHeight;
	float mTextureWidth;

};


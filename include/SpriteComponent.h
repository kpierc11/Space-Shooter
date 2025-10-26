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
	void SetTextureWidth(int width) { mTextureWidth = width; }
	int GetTextureWidth() { return mTextureWidth; }
	void SetTextureHeight(int height) { mTextureWidth = height; }
	int GetDrawOrder() { return mDrawOrder; }




protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTextureHeight;
	int mTextureWidth;

};


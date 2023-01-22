#pragma once
#include <SDL_render.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Component.h"

class SpriteComponent : public Component
{

public:
	//default constructor
	SpriteComponent(class Actor* owner, int drawOrder = 10);

	~SpriteComponent();

	virtual void Draw(SDL_Renderer* renderer);

	//getter/setters
	virtual void SetTexture(SDL_Texture* texture);
	int GetTextureHeight() { return mTextureHeight; }
	void SetTextureWidth(int width) { mTextureWidth = width; }
	int GetTextureWidth() { return mTextureWidth; }
	void SetTextureHeight(int height) { mTextureWidth = height; }




protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTextureHeight;
	int mTextureWidth;

};


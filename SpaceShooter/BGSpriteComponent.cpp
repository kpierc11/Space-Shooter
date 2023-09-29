#include "BGSpriteComponent.h"
#include <iostream>

BGSpriteComponent::BGSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	,mScrollSpeed(0.0f)
{
}

void BGSpriteComponent::Update(float deltaTime)
{

	SpriteComponent::Update(deltaTime);
	for (auto& bg : mBGTextures)
	{
		bg.mOffset.y -= mScrollSpeed * deltaTime;
		
		if (bg.mOffset.y > mScreenSize.y)
		{
			bg.mOffset.y = -mScreenSize.y;
		}
	}

}

void BGSpriteComponent::Draw(SDL_Renderer* renderer)
{
	
	// Draw each background texture
	for (auto& bg : mBGTextures)
	{
		SDL_Rect r{};

		// Assume screen size dimensions
		r.w = static_cast<int>(mScreenSize.x);
		r.h = static_cast<int>(mScreenSize.y);
		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / static_cast<float>(2) + bg.mOffset.x);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / static_cast<float>(2) + bg.mOffset.y);

		// Draw this background
		SDL_RenderCopy(renderer,
			bg.mTexture,
			nullptr,
			&r
		);
	}
}

void BGSpriteComponent::SetBGTextures(const std::vector<SDL_Texture*>& textures)
{
	int count = 0;
	for (auto tex : textures)
	{
		BGTexture temp;
		temp.mTexture = tex;
		// Each texture is screen width in offset
		temp.mOffset.x = 0;
		temp.mOffset.y = count * -mScreenSize.y;
		mBGTextures.emplace_back(temp);
		count++;
	}
}

#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	:Component(owner)
	, mTexture(nullptr)
	, mDrawOrder(drawOrder)
	, mTextureHeight(0)
	, mTextureWidth(0)
{
	mOwner->GetGame()->AddSpriteComponent(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSpriteComponent(this);
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{

	if (mTexture) {

		SDL_FRect r = {};

		//Scale the width/height by owner's scale
		r.w = static_cast<int>(mTextureWidth * mOwner->GetScale());
		r.h = static_cast<int>(mTextureHeight * mOwner->GetScale());

		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / static_cast<float>(2));
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / static_cast<float>(2));

		SDL_RenderTextureRotated(renderer, mTexture, NULL, &r, -GameMath::ToDegrees(mOwner->GetRotation()), NULL, SDL_FLIP_NONE);

	}

}

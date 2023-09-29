#include <vector>
#include "SpriteComponent.h"
#include "GameMath.h"

class BGSpriteComponent : public SpriteComponent
{
	
public:
	BGSpriteComponent(class Actor* owner, int drawOrder = 10);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

	void SetBGTextures(const std::vector<SDL_Texture*>& textures);

	void SetScreenSize(const GameMath::Vector2& size) { mScreenSize = size; }
	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
	float GetScrollSpeed() const { return mScrollSpeed; }


private:
	struct BGTexture
	{
		SDL_Texture* mTexture;
		GameMath::Vector2 mOffset;
	};
	std::vector<BGTexture> mBGTextures;
	GameMath::Vector2 mScreenSize;
	float mScrollSpeed;
};


#include "Score.h"
#include "SpriteComponent.h"

Score::Score(Game* game)
	:Actor(game),
	mScore(0)
{
	/*SpriteComponent* score = new SpriteComponent(this);
	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceScore = TTF_RenderText_Solid(Sans, "1", White);
	SDL_Texture* blankTexture = game->LoadEmptyTexture(100, 100);
	score->SetTexture(blankTexture);
	this->SetPosition({100,100});
	this->SetScale(2);*/

}

Score::~Score()
{
}

void Score::Update(float deltaTime)
{
}

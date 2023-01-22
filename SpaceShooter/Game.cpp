#include "Game.h"
#include <string>
#include <time.h>
#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include <iostream>
#include "Ship.h"
#include "bullet.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
Uint32 previousFrameTime = 0.0f;

Game::Game() {
    mGameRunning = true;
    mRenderer = {};
    mWindow = {};
}

Game::~Game() {

}

bool Game::Initialize() {

    int result = SDL_Init(SDL_INIT_VIDEO);

    mWindow = SDL_CreateWindow(
        "Chess game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL

    );

    if (mWindow == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mRenderer == NULL) {
        printf("Could not create Renderer: %s\n", SDL_GetError());
        return false;
    }

    int imageInit = IMG_Init(IMG_INIT_PNG);

    if (imageInit == 0) {
        printf("Could not Initialize image: %s\n", SDL_GetError());
        return false;
    }

    SDL_Texture* background = LoadTexture("assets/space-background.png");
    SDL_Texture* ship = LoadTexture("assets/space-ship.png");

    //background
    Actor* bgActor = new Actor(this);
    bgActor->SetPosition({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
    bgActor->SetScale(1);

    SpriteComponent* bgSprite = new SpriteComponent(bgActor);

    bgSprite->SetTexture(background);
    bgSprite->SetTextureWidth(1024);
    bgSprite->SetTextureHeight(1024);

    //ship
    Ship* shipActor = new Ship(this);
    shipActor->SetPosition({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
    shipActor->SetScale(2);

    SpriteComponent* shipSprite = new SpriteComponent(shipActor);
    shipSprite->SetTexture(ship);

    mActors.push_back(bgActor);
    mActors.push_back(shipActor);

    mSpriteComponents.emplace_back(bgSprite);
    mSpriteComponents.emplace_back(shipSprite);



}

void Game::GameLoop() {

    while (mGameRunning) {
        HandleInput();
        UpdateGame();
        GenerateOutput();
    }

}

void Game::HandleInput() {
    //SDl Event var
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            mGameRunning = false;
            break;

        case SDL_KEYDOWN:
            mKeyDown = true;
            break;
        }

    }

    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    for (auto actor : mActors) {
        actor->HandleInput(keyboardState, mKeyDown);
    }


}

void Game::UpdateGame() {
    float deltaTime = (SDL_GetTicks() - previousFrameTime) / 1000.0f;
    previousFrameTime = SDL_GetTicks();


    while (!SDL_TICKS_PASSED(SDL_GetTicks(), previousFrameTime + 16));
    std::cout << deltaTime << std::endl;

    for (auto actor : mActors)
    {
        actor->Update(deltaTime);
    }


}

void Game::GenerateOutput() {

    //set initial background color
    SDL_SetRenderDrawColor(mRenderer, 30, 81, 123, 1);

    //clear renderer
    SDL_RenderClear(mRenderer);

    //render sprite components
    for (auto sprite : mSpriteComponents)
    {
        sprite->Draw(mRenderer);
    }

    SDL_RenderPresent(mRenderer);
}

SDL_Texture* Game::LoadTexture(const std::string& fileName)
{
    SDL_Texture* texture = IMG_LoadTexture(mRenderer, fileName.c_str());

    if (texture == NULL) {
        printf("Could not load texture: %s\n", SDL_GetError());
    }
    return texture;
}

void Game::AddActors(Actor* actor)
{
    mActors.push_back(actor);
}

void Game::RemoveActor(Actor* actor)
{
    //Check if its in actors 
    auto iter = std::find(mActors.begin(), mActors.end(), actor);

    if (iter != mActors.end())
    {
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::AddSpriteComponent(SpriteComponent* spriteComponent)
{

    mSpriteComponents.push_back(spriteComponent);
}

void Game::RemoveSpriteComponent(SpriteComponent* spriteComponent)
{
    //Check if its in sprites vector 
    auto iter = std::find(mSpriteComponents.begin(), mSpriteComponents.end(), spriteComponent);

    if (iter != mSpriteComponents.end())
    {
        std::iter_swap(iter, mSpriteComponents.end() - 1);
        mSpriteComponents.pop_back();
    }
}

void Game::UnloadData()
{
    while (!mActors.empty()) {
        delete mActors.back();
    }
}


void Game::EndGame() {
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    UnloadData();
    SDL_Quit();
}
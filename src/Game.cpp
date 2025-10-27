#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>

#include "GameMath.h"
#include "Game.h"
#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "GameLevel.h"

using namespace GameMath;

Uint32 previousFrameTime = 0.0f;

Game::Game()
{
    mGameRunning = true;
    mWindowSize = {1024.0, 768.0};
    mRenderer = nullptr;
    mWindow = nullptr;
    mLevel = nullptr;
    mKeyDown = false;
    mLevel = nullptr;
}

Game::~Game()
{
}

bool Game::Initialize()
{

    mWindow = SDL_CreateWindow(
        "Space Shooter",
        mWindowSize.width,
        mWindowSize.height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE

    );

    if (mWindow == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, "");

    if (mRenderer == NULL)
    {
        printf("Could not create Renderer: %s\n", SDL_GetError());
        return false;
    }

    // int ttfInit = TTF_Init();

    // /* Initialize the TTF library */
    // if (ttfInit < 0)
    // {
    //     SDL_Log("Couldn't initialize TTF: %s\n", SDL_GetError());
    //     return false;
    // }

    // srand((unsigned)time(0));

    mLevel = new GameLevel(this);
    mLevel->InitLevel();

    return true;
}

void Game::GameLoop()
{

    while (mGameRunning)
    {
        HandleInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::HandleInput()
{
    // SDl Event var
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            mGameRunning = false;
            break;

        case SDL_EVENT_KEY_DOWN: 
            mKeyDown = true;
            break;

        case SDL_EVENT_KEY_UP:
            mKeyDown = false;
            break;

        case SDL_EVENT_WINDOW_RESIZED: 
           
            mWindowSize.width = event.window.data1;
            mWindowSize.height = event.window.data2;
            break;

        default:
            break;
        }
    }

    // int *keyboardState = SDL_GetKeyboardState();

    for (auto actor : mActors)
    {
        // actor->HandleInput(keyboardState, mKeyDown);
    }
}

void Game::UpdateGame()
{

    Uint64 currentTicks = SDL_GetTicks();
    float deltaTime = (currentTicks - previousFrameTime) / 1000.0f;
    previousFrameTime = currentTicks;

    while ((SDL_GetTicks() - previousFrameTime) < 16)
    {
        SDL_Delay(1); // Yield CPU briefly instead of busy-waiting
    }

    // Update all actors
    for (auto actor : mActors)
    {
        actor->Update(deltaTime);
    }

    // Update level logic
    if (mLevel)
    {
        mLevel->UpdateLevel();
    }
}

void Game::GenerateOutput()
{

    // set initial background color
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 1);

    // clear renderer
    SDL_RenderClear(mRenderer);

    // render sprite components
    for (auto sprite : mSpriteComponents)
    {
        sprite->Draw(mRenderer);
    }

    SDL_RenderPresent(mRenderer);
}

SDL_Texture *Game::LoadTexture(const std::string &fileName)
{
    SDL_Texture *texture = IMG_LoadTexture(mRenderer, fileName.c_str());

    if (texture == NULL)
    {
        printf("Could not load texture: %s\n", SDL_GetError());
    }
    return texture;
}

SDL_Texture *Game::LoadEmptyTexture(int width, int height)
{

    SDL_Texture *emptyTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height);

    return emptyTexture;
}

void Game::AddActors(Actor *actor)
{
    mActors.push_back(actor);
}

void Game::RemoveActor(Actor *actor)
{
    // Check if its in actors
    auto iter = std::find(mActors.begin(), mActors.end(), actor);

    if (iter != mActors.end())
    {
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::AddSpriteComponent(SpriteComponent *spriteComponent)
{
    int drawOrder = spriteComponent->GetDrawOrder();
    auto iter = mSpriteComponents.begin();

    for (; iter != mSpriteComponents.end(); iter++)
    {
        if (drawOrder < (*iter)->GetDrawOrder())
        {
            break;
        }
    }

    mSpriteComponents.insert(iter, spriteComponent);
}

void Game::RemoveSpriteComponent(SpriteComponent *spriteComponent)
{
    // Check if its in sprites vector
    auto iter = std::find(mSpriteComponents.begin(), mSpriteComponents.end(), spriteComponent);

    if (iter != mSpriteComponents.end())
    {
        std::iter_swap(iter, mSpriteComponents.end() - 1);
        mSpriteComponents.pop_back();
    }
}

void Game::UnloadData()
{
    while (!mActors.empty())
    {
        delete mActors.back();
    }

    delete mLevel;
}

void Game::EndGame()
{
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    UnloadData();
    // TTF_Quit();
    SDL_Quit();
}
#include <iostream>
#include <string>
#include <time.h>
#include <iostream>


#include "Game.h"
#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "Ship.h"
#include "Bullet.h"
#include "BGSpriteComponent.h"

 float screenWidth = 1024.0;
 float screenHeight = 768.0;
Uint32 previousFrameTime = 0.0f;

Game::Game() {
    mGameRunning = true;
    mRenderer = {};
    mWindow = {};
}

Game::~Game() {

}

bool Game::Initialize() {

    /*int result = SDL_Init(SDL_INIT_VIDEO);

    if (result == NULL) {
        printf("Could not initialize sound: %s\n", SDL_GetError());
        return false;
    }*/

    mWindow = SDL_CreateWindow(
        "Space Shooter",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        screenWidth,
        screenHeight,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE

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

    int ttfInit = TTF_Init();

    /* Initialize the TTF library */
    if (ttfInit < 0) {
        SDL_Log("Couldn't initialize TTF: %s\n", SDL_GetError());
        return false;
    }

    LoadGameData();

    return true; 

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

        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                std::cout << event.window.data1 << std::endl;
                std::cout << event.window.data2 << std::endl;
                screenWidth = event.window.data1;
                screenHeight = event.window.data2;
            }
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
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 1);

    //clear renderer
    SDL_RenderClear(mRenderer);

    //render sprite components
    for (auto sprite : mSpriteComponents)
    {
        sprite->Draw(mRenderer);
    }

    SDL_RenderPresent(mRenderer);

    SDL_GetWindowSize(mWindow, NULL, NULL);

 
}

SDL_Texture* Game::LoadTexture(const std::string& fileName)
{
    SDL_Texture* texture = IMG_LoadTexture(mRenderer, fileName.c_str());

    if (texture == NULL) {
        printf("Could not load texture: %s\n", SDL_GetError());
    }
    return texture;
}

SDL_Texture* Game::LoadEmptyTexture(int width, int height) {

    SDL_Texture* emptyTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height);

    return emptyTexture;
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
    int drawOrder = spriteComponent->GetDrawOrder();
    auto iter = mSpriteComponents.begin();

    for (; iter != mSpriteComponents.end(); iter++) {
        if (drawOrder < (*iter)->GetDrawOrder()) {
            break;
        }
    }


    mSpriteComponents.insert(iter, spriteComponent);
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

void Game::LoadGameData()
{
    //ship
    Ship* shipActor = new Ship(this);
    shipActor->SetPosition({screenHeight / 2,screenWidth / 2 });
    shipActor->SetScale(.2);

    // Create actor for the background (this doesn't need a subclass)
   /* Actor* temp = new Actor(this);
    temp->SetPosition({ 512.0f, 384.0f });*/

    //BGSpriteComponent* bg = new BGSpriteComponent(temp);
    //bg->SetScreenSize({ 1024.0f, 768.0f });
    //std::vector<SDL_Texture*> bgtexs = {
    //    LoadTexture("assets/Farback01.png"),
    //    LoadTexture("assets/Farback02.png")
    //};
    //bg->SetBGTextures(bgtexs);
    //bg->SetScrollSpeed(-100.0f);
    //// Create the closer background
    //bg = new BGSpriteComponent(temp, 1);
    //bg->SetScreenSize({ 1024.0f, 768.0f });
    //bgtexs = {
    //    LoadTexture("assets/Stars.png"),
    //    LoadTexture("assets/Stars.png")
    //};
    //bg->SetBGTextures(bgtexs);
    //bg->SetScrollSpeed(-200.0f);

    //Initial Font Type
    TTF_Font* font = TTF_OpenFont("assets/fonts/arial.ttf", 25);

    //color 
    SDL_Color color = { 178,34,34 };


    //1up Text
    Actor* tempScoreActor = new Actor(this);
    tempScoreActor->SetPosition({ screenWidth / 4, 30 });
    tempScoreActor->SetScale(2);

    SpriteComponent* score = new SpriteComponent(tempScoreActor, 40);

    SDL_Surface* surface = TTF_RenderText_Solid(font, "1up", color);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);

    score->SetTexture(texture);


    //HighScore Text
    Actor* highScoreActor = new Actor(this);
    highScoreActor->SetPosition({ screenWidth / 2, 30 });
    highScoreActor->SetScale(2);

    SpriteComponent* highScore = new SpriteComponent(highScoreActor, 40);

    SDL_Surface* highScoreSurface = TTF_RenderText_Solid(font, "HighScore", color);

    SDL_Texture* highScoreTexture = SDL_CreateTextureFromSurface(mRenderer, highScoreSurface);

    highScore->SetTexture(highScoreTexture);


    //free font resource
    TTF_CloseFont(font);

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
    TTF_Quit();
    SDL_Quit();
}